/*

代理模式（Proxy Pattern）是一种设计模式，它为其他对象提供一种代理以控制对这个对象的访问。
在C++中实现代理模式，通常有几种常见的场景，例如虚拟代理、远程代理、保护代理等。

场景描述
假设我们有一个图片加载的类Image，当我们尝试加载一个图片时，可能会因为图片很大而消耗很多内存和时间。
为了优化这个加载过程，我们可以使用代理模式，通过一个ImageProxy类来延迟加载图片。

实现步骤
‌定义接口‌：首先定义一个图像接口Image，所有的实现类都需要实现这个接口。
‌实现具体类‌：创建一个具体的图像类RealImage来实现这个接口。
‌创建代理类‌：创建一个代理类ImageProxy，它也实现Image接口，并在需要时创建并使用RealImage对象。

*/

#include <iostream>
#include <string>

// 定义图像接口
class Image {
public:
	virtual ~Image() {}
	virtual void display() = 0;
};

// 具体图像类
class RealImage : public Image {
private:
	std::string filename;
	bool loaded;

public:
	RealImage(const std::string& fileName) : filename(fileName), loaded(false) {}
	void display() override {
		if (!loaded) {
			loadFromDisk(); // 模拟从磁盘加载图片
			loaded = true;
		}
		std::cout << "Displaying " << filename << std::endl;
	}

private:
	void loadFromDisk() {
		std::cout << "Loading " << filename << std::endl;
		// 这里可以是耗时的磁盘操作或其他资源加载操作
	}
};

// 代理类
class ImageProxy : public Image {
private:
	RealImage* realImage;
	std::string filename;

public:
	ImageProxy(const std::string& fileName) : filename(fileName), realImage(nullptr) {}
	void display() override {
		if (!realImage) {
			realImage = new RealImage(filename); // 延迟加载真实对象
		}
		realImage->display(); // 调用真实对象的display方法
	}
};

int main() {

	Image* image = new ImageProxy("test.jpg"); // 创建代理对象，延迟加载图片
	image->display(); // 显示图片，此时才会真正加载图片到内存中
	delete image; // 清理资源，删除代理对象，实际对象会在适当的时候被删除（依赖于具体的实现细节）

	system("pause");
	return 0;
}