#pragma once

/*
	版本1：现代C++懒汉式（局部静态变量版，最优）

	核心思想

		利用C++11的特性：局部静态变量的初始化是线程安全的——多个线程同时访问局部静态变量的初始化语句时，只会有一个线程执行初始化，其他线程阻塞等待。无需手动加锁，代码更简洁、安全。
*/

/*
	完整代码
*/

#include <iostream>
using namespace std;

// 单例类声明
class Singleton1 {
private:
	// 构造函数私有化
	Singleton1();

	// 删除拷贝构造、赋值运算符（禁止拷贝）
	Singleton1(const Singleton1&) = delete;
	Singleton1& operator=(const Singleton1&) = delete;

public:
	// 获取单例实例
	static Singleton1& getInstance();

	// 成员函数
	void show();
};

/*
	优缺点及适用场景

		优点：代码最简洁（无需管理静态指针、互斥锁），线程安全（依赖C++11特性），延迟加载，无内存泄漏（局部静态变量在程序结束时自动销毁）。

		缺点：仅支持C++11及以上标准，若项目需兼容旧标准（如C++98），则无法使用。

		适用场景：C++11及以上环境，是现代C++开发中最推荐的单例实现方式（简洁、安全、高效）。
*/