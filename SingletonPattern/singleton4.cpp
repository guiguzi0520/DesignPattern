#include "singleton4.h"

// 构造函数实现
Singleton4::Singleton4() {
	cout << "线程安全版懒汉式单例实例创建" << endl;
}

// 静态成员变量初始化（必须写在 .cpp 中）
Singleton4* Singleton4::instance = nullptr;
mutex Singleton4::mtx;

// 获取单例（双重检查锁定 DCLP）
Singleton4* Singleton4::getInstance() {
	if (instance == nullptr) {
		lock_guard<mutex> lock(mtx);
		if (instance == nullptr) {
			instance = new Singleton4();
		}
	}
	return instance;
}

// 成员函数
void Singleton4::show() {
	cout << "单例实例正在工作（线程安全版）" << endl;
}

// 销毁实例
void Singleton4::destroyInstance() {
	lock_guard<mutex> lock(mtx);
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}