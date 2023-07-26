/*
  FileName:T7_29.cpp
  Author:yangjiasen
  E-mail:2462980372@qq.com
  Time:Apr 25th,2022
  College:School of Computer Science and Information Engineeering
*/
//�ݹ���ݽ���˻ʺ����� 
#include<iostream>
#include <cmath>
using namespace std;

//����������Żʺ����ڵ�����������n��n�У���sum�ֽⷨ 
int a[10], n, num;

//����ܷ��ڸ�λ�÷��ûʺ� ��kΪ��ǰ�ʺ����ڵ����� 
bool check(int a[], int k)
{
	for (int i = 1; i <= k - 1; i++)
	{
		if ((fabs(a[i] - a[k]) == k - i) || (a[i] == a[k]))
//�����ǰλ�õ���б�Ϸ�������б�Ϸ��лʺ󣬻���ͬһ���лʺ󷵻�false
			return false;
	}
	return true;
}

//kΪ���� 
void backtrack(int k)
{
	if (k>n)//�����Ѿ��ҵ��� 
	{
		//������лʺ����ڵ����� 
		for (int i = 1; i <= 8; i++)
		{
			cout << a[i];
		}
		cout << endl;
		num++;   
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			a[k] = i;
			if (check(a, k))
			{
				backtrack(k + 1);
			}
		}
	}

}

int main()
{
	n = 8, num = 0;
	backtrack(1);
	cout <<"The ways of queens is" <<num << endl;
	return 0;
}
