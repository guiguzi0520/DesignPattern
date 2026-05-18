#pragma once

/*
	版本3：懒汉式单例（基础版，非线程安全）

	核心思想

		延迟加载：程序启动时不创建实例，第一次调用 getInstance() 时，才创建实例，后续调用直接返回，避免资源浪费。
*/

/*
	完整代码
*/

#include <iostream>
using namespace std;

class Singleton3 {
private:
	// 构造函数声明
	Singleton3();

	// 禁止拷贝、赋值
	Singleton3(const Singleton3&) = delete;
	Singleton3& operator=(const Singleton3&) = delete;

	// 静态成员指针声明
	static Singleton3* instance;

public:
	// 获取单例
	static Singleton3* getInstance();

	// 成员函数
	void show();

	// 释放实例
	static void destroyInstance();
};



/*
	优缺点及适用场景

		优点：延迟加载，避免资源浪费，实例仅在需要时创建。

		缺点：非线程安全！多线程环境下，多个线程可能同时进入 if (instance == nullptr)，导致创建多个实例，打破单例约束。

		适用场景：仅适用于单线程环境（如简单的控制台程序），实际开发中（多线程）禁止使用。

*/