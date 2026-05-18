#pragma once

/*
	版本2：饿汉式单例（基础版，线程安全）

	核心思想
	
		程序启动时（全局静态变量初始化阶段），就主动创建单例实例，后续调用访问接口时，直接返回已创建的实例，无需动态创建。
*/

/*
	完整代码
*/

#include <iostream>
using namespace std;

// 饿汉式单例类
class Singleton2 {
private:
	// 1. 私有构造函数（禁止外部实例化）
	Singleton2();

	// 2. 私有拷贝构造和赋值运算符（禁止拷贝）
	Singleton2(const Singleton2&) = delete;
	Singleton2& operator=(const Singleton2&) = delete;

	// 3. 私有静态成员（程序启动时初始化，全局唯一）
	static Singleton2 instance;

public:
	// 4. 公有静态访问接口（唯一入口）
	static Singleton2& getInstance();

	// 测试方法（模拟实际功能）
	void show();
};



/*
	优缺点及适用场景

		优点：实现简单，无需考虑线程安全（C++中全局静态变量的初始化是线程安全的），访问速度快，无延迟。

		缺点：实例提前创建，若实例创建成本高（如加载大量配置、创建数据库连接），且程序全程未使用，会造成资源浪费。

		适用场景：单例实例创建成本低、程序启动后一定会使用该实例（如简单的全局配置管理器）。

*/