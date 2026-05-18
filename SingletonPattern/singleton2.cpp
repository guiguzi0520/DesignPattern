#include "singleton2.h"

// 【饿汉式核心】全局静态变量初始化（程序启动时就创建）
Singleton2 Singleton2::instance;

// 构造函数实现
Singleton2::Singleton2() {
	cout << "饿汉式单例实例创建" << endl;
}

// 获取单例对象
Singleton2& Singleton2::getInstance() {
	return instance;
}

// 成员函数实现
void Singleton2::show() {
	cout << "单例实例正在工作（饿汉式）" << endl;
}