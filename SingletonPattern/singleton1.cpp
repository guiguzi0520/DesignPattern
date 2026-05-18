#include "singleton1.h"

// 构造函数实现
Singleton1::Singleton1() {
	cout << "现代C++懒汉式单例实例创建" << endl;
}

// 获取单例实例（核心：局部静态变量，C++11线程安全）
Singleton1& Singleton1::getInstance() {
	static Singleton1 instance;
	return instance;
}

// 成员函数实现
void Singleton1::show() {
	cout << "单例实例正在工作（现代C++版）" << endl;
}