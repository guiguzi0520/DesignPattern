#pragma once

/*
	版本4：懒汉式单例（线程安全版，推荐）

	核心思想

		在基础懒汉式的基础上，添加互斥锁（std::mutex），保证多线程环境下，只有一个线程能创建实例；同时采用“双重检查锁定（DCLP）”，减少锁的开销，兼顾线程安全和效率。
*/

/*
	完整代码
*/

#include <iostream>
#include <mutex>  // 线程安全必须
using namespace std;

class Singleton4 {
private:
	// 构造函数
	Singleton4();

	// 禁止拷贝、赋值
	Singleton4(const Singleton4&) = delete;
	Singleton4& operator=(const Singleton4&) = delete;

	// 静态成员变量声明
	static Singleton4* instance;
	static mutex mtx;

public:
	// 获取单例实例
	static Singleton4* getInstance();

	// 功能函数
	void show();

	// 释放实例
	static void destroyInstance();
};


/*
	关键注意点

		1. 互斥锁（std::mutex）：C++11及以上标准才支持，需包含 <mutex> 头文件。

		2. 双重检查锁定（DCLP）：两次检查 instance == nullptr，第一次检查避免频繁加锁（提升效率），第二次检查确保唯一实例。

		3. 内存释放：手动调用 destroyInstance() 释放内存，避免内存泄漏；也可结合智能指针（std::unique_ptr）自动管理内存（后续优化版会讲）。

		适用场景：多线程环境（如服务器程序、多线程控制台程序），是实际开发中最常用的懒汉式版本。

*/