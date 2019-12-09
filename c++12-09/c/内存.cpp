#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void main()
{
	int *p1 = new int(10);
	int *p2 = new int[10];//申请连续数组空间10个
	cout << *p1 << endl;
	delete(p1);
	delete[]p2;
	//new           1 申请空间  2调动构造函数
 	//delete        1 析构函数  2释放空间
}