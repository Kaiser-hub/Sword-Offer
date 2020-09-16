#include<iostream>

using namespace std;

//C#的sealed关键字和Java的final关键字，可以使一个类成为不可继承类,从而形成单例模式，但C++中没有这样作用的关键字
/*单例模式也称为单件模式、单子模式，可能是使用最广泛的设计模式。
其意图是保证一个类仅有一个实例，并提供一个访问它的全局访问点，该实例被所有程序模块共享。*/

//定义一个单例类，使用类的私有静态指针变量指向类的唯一实例，并用一个公有的静态方法获取该实例。
//懒汉模式
class Singleton {
private:
	//构造函数私有化
	Singleton() {}
	
	//指向唯一实例的静态指针M_Instance，并且是私有的
	static Singleton* M_Instance;
	class CleanGarbage {
	public:
		~CleanGarbage() {
			if (Singleton::M_Instance != NULL) {
				delete Singleton::M_Instance;
			}
		}
	};

	static CleanGarbage CG;
public:
	/*用户访问唯一实例的方法只有GetInstance()成员函数。
	如果不通过这个函数，任何创建实例的尝试都将失败，因为类的构造函数是私有的。
	GetInstance()使用懒惰初始化，也就是说它的返回值是当这个函数首次被访问时被创建的*/
	static Singleton* GetInstance() {
		if (M_Instance == NULL) {
			M_Instance = new Singleton();
		}
		return M_Instance;
	}
};

//饿汉模式
class Singleton2 {
private:
	//构造函数私有化
	Singleton2() {}
	Singleton2(const Singleton2&);
	Singleton2& operator = (const Singleton2&);
public:
	static Singleton2* GetInstance() {
		//局部静态变量
		static Singleton2 instance;
		return &instance;
	}
};