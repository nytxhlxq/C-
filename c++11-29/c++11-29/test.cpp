#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*
class Test
{
public:
	//��������ͬ�����캯����
	Test(int d = 0) : m_data(d)
	{}
	//1.��������const ��ô��                      �����޸ĺ������õ�private�еĲ���
	//2.GetData������GetData����const�Ƿ񹲴�     ����
	//3.�������캯����const                       ��������������ǰ����һ����
	//4.��ֵ���	
	//  Test& operator = ��const Test &t��        ͬ�ϣ�������������&���ɣ��޵Ļ����һ�ο������캯��(operator=Ϊһ������)
	//  void operator = ��Test t��                ��������t1 = t2 = t3 <=> t1.operator=(t2.operator(t3.operator))
	/////////////////////////////////////////     t1 = t2;t1.operator(t2); <=> operator=(&t1,t2) <=> this����t1




	int GetData()const;// <=> int GetData(const Test * const this); <=>ʹ�� *this ��ɳ�����
	int GetData();// <=> int GetData(Test * const this); <=>*this ���ǳ��ģ�
	Test& operator=(Test t);//��������� =
private:
	int m_data;
	//int m_data = 0;
};
*/


//sizeof     ar[10] = "HELLO"��δ��ȫ��ʼ����,��Ϊ10��!! �� H,E,L,L,O ���Զ�����10��
//strlen     ׷\0,��\0��ͣ(����\0)��һ��Ϊ�����ĸ��� + 1,ar[10] = {'h','e','l','l','o','w','o','r','l','d'}Ϊ����10�����ֵ��ar[10]����ȫ�ֵ�ʱ��Ϊ0


class String
{
public:
	String(const char *str = "")
	//String(const char *str NULL);
	{
		/*
		int len = sizeof(str);
		m_data = (char*)malloc(len);
		*/                          //����
		m_data = (char *)malloc(strlen(str) + 1);
	}
private:
	char *m_data;
};

void main()
{
	String s1("Hello bit.");
}