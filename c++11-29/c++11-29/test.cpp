#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*
class Test
{
public:
	//与类名相同（构造函数）
	Test(int d = 0) : m_data(d)
	{}
	//1.常方法的const 怎么了                      不能修改函数引用的private中的参数
	//2.GetData（）与GetData（）const是否共存     可以
	//3.拷贝构造函数的const                       保护参数（拷贝前后需一样）
	//4.赋值语句	
	//  Test& operator = （const Test &t）        同上（保护），有无&都可，无的话会调一次拷贝构造函数(operator=为一个函数)
	//  void operator = （Test t）                不能连等t1 = t2 = t3 <=> t1.operator=(t2.operator(t3.operator))
	/////////////////////////////////////////     t1 = t2;t1.operator(t2); <=> operator=(&t1,t2) <=> this就是t1




	int GetData()const;// <=> int GetData(const Test * const this); <=>使得 *this 变成常量；
	int GetData();// <=> int GetData(Test * const this); <=>*this 不是常的；
	Test& operator=(Test t);//运算符重载 =
private:
	int m_data;
	//int m_data = 0;
};
*/


//sizeof     ar[10] = "HELLO"（未完全初始化）,则为10个!! 除 H,E,L,L,O 外自动补够10个
//strlen     追\0,到\0就停(算上\0)，一般为看见的个数 + 1,ar[10] = {'h','e','l','l','o','w','o','r','l','d'}为大于10的随机值，ar[10]放在全局的时候为0


class String
{
public:
	String(const char *str = "")
	//String(const char *str NULL);
	{
		/*
		int len = sizeof(str);
		m_data = (char*)malloc(len);
		*/                          //错误
		m_data = (char *)malloc(strlen(str) + 1);
	}
private:
	char *m_data;
};

void main()
{
	String s1("Hello bit.");
}