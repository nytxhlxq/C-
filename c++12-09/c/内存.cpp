#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void main()
{
	int *p1 = new int(10);
	int *p2 = new int[10];//������������ռ�10��
	cout << *p1 << endl;
	delete(p1);
	delete[]p2;
	//new           1 ����ռ�  2�������캯��
 	//delete        1 ��������  2�ͷſռ�
}