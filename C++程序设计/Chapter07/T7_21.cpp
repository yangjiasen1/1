/* 
  FileName:T7_21.cpp
  Author:yangjiasen
  E-mail:2462980372@qq.com
  Time:Apr 10th,2022
  College:School of Computer Science and Information Engineeering
*/
#include <iostream>
#include <array>
using namespace std;

const int r = 6;
const int c = 5;

int main()
{
	array<array<int,c>,r>a;
	int m,n;
	int x;
	//��������Сֽ�������������� 
	for(int i = 0;i<600;i++)
	{
		cin >> m >> n >> x;
		a[n][m] = x;
	}
	//��ÿ�ֲ�Ʒ�ܵ����۶� 
	for(int j = 0;j<5;j++)
	{
	int sum = 0;
	for(int i = 0;i<4;i++)
	{
		sum+=a[j][i];
	} 
	a[j][5] = sum;
	sum = 0;
    }
	//��ÿλԱ���ܵ����۶� 
	for(int j = 0;j<4;j++)
	{
	int sum = 0;
	for(int i = 0;i<5;i++)
	{
		sum+=a[i][j];
	} 
	a[6][j] = sum;
	sum = 0;
    }
    //������ 
    for(int j = 0;j<5;j++)
    {
    	cout << j+1 << "��Ա��" << "\t";
	for(int i = 0;i<5;i++)
	{
		cout << a[j][i] << " ";
	 }
	 cout << endl;
    }
	cout << "�����ܶ�" << "\t";
	for(int i = 0;i<5;i++)
	{
		cout << a[5][i] << " ";
	} 	
	
	return 0;
}
