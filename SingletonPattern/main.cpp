#include "singleton1.h"
#include "singleton2.h"
#include "singleton3.h"
#include "singleton4.h"

/*
	常见问题与注意事项（易错点，必记）

		1. 避免“伪单例”：必须同时禁用构造函数、拷贝构造、赋值运算符，否则外部可能通过拷贝、赋值创建新实例。

		2. 线程安全问题：仅饿汉式（全局静态变量）、线程安全懒汉式（加锁）、现代C++懒汉式（局部静态变量）支持多线程，基础懒汉式不可用于多线程。

		3. 内存泄漏：懒汉式（指针版）需手动释放内存（如调用 destroyInstance()），或使用智能指针优化；局部静态变量版无需手动释放。

		4. 静态成员初始化：饿汉式的静态实例需在类外初始化，否则会编译报错。

		5. 不能滥用单例：单例模式会增加类的耦合度，若一个类不需要全局唯一实例，切勿强行使用单例（如普通的工具类）。

	实战应用场景（结合C++面向对象）

		单例模式的核心价值是“全局唯一”，以下是C++开发中最常见的实战场景，可直接参考使用：

		1. 日志器（Logger）：整个程序只需一个日志器实例，负责所有模块的日志输出，避免多个日志器同时写入导致日志错乱。

		2. 配置管理器（ConfigManager）：读取配置文件（如config.ini），全局提供配置参数（如端口号、数据库地址），避免重复读取配置文件。

		3. 数据库连接池（DBConnectionPool）：管理数据库连接，避免频繁创建、销毁连接造成的性能损耗，确保连接资源唯一。

		4. 全局计数器：统计程序中某个事件的发生次数（如接口调用次数），全局唯一计数，避免多实例计数混乱。


	总结（核心要点提炼）

		1. 单例模式核心：唯一实例 + 全局唯一访问入口。

		2. 实现约束：私有构造、私有拷贝/赋值、公有静态访问接口。

		3. 常用版本选择：

		- 简单场景、C++11以下：饿汉式。

		- 多线程、C++11以下：线程安全懒汉式（加锁+DCLP）。

		- 多线程、C++11及以上：现代C++懒汉式（局部静态变量，最优）。

		4. 注意：不滥用、防伪单例、防线程安全问题、防内存泄漏。
*/

void Test1()
{
	Singleton1& s1 = Singleton1::getInstance();
	Singleton1& s2 = Singleton1::getInstance();

	cout << "s1地址：" << &s1 << endl;
	cout << "s2地址：" << &s2 << endl;

	s1.show();
}

void Test2()
{
	Singleton2& s1 = Singleton2::getInstance();
	Singleton2& s2 = Singleton2::getInstance();

	cout << "s1地址：" << &s1 << endl;
	cout << "s2地址：" << &s2 << endl;

	s1.show();
}

void Test3()
{
	Singleton3* s1 = Singleton3::getInstance();
	Singleton3* s2 = Singleton3::getInstance();

	cout << "s1地址：" << s1 << endl;
	cout << "s2地址：" << s2 << endl;

	s1->show();

	delete s1;
}

void Test4()
{
	Singleton4* s1 = Singleton4::getInstance();
	Singleton4* s2 = Singleton4::getInstance();

	cout << "s1地址：" << s1 << endl;
	cout << "s2地址：" << s2 << endl;

	s1->show();

	delete s1;
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	system("pause");
	return 0;
}