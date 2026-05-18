#include "singleton3.h"

// 构造函数实现
Singleton3::Singleton3() {
	cout << "懒汉式单例实例创建" << endl;
}

// 静态成员变量初始化（必须写在 cpp 里）
Singleton3* Singleton3::instance = nullptr;

// 获取单例实例
Singleton3* Singleton3::getInstance() {
	if (instance == nullptr) {
		instance = new Singleton3();
	}
	return instance;
}

// 成员函数实现
void Singleton3::show() {
	cout << "单例实例正在工作（懒汉式基础版）" << endl;
}

// 释放内存
void Singleton3::destroyInstance() {
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}