/*
  FileName:T7_28.cpp
  Author:yangjiasen
  E-mail:2462980372@qq.com
  Time:Apr 25th,2022
  College:School of Computer Science and Information Engineeering
*/
#include <iostream>
#include <vector>
using namespace std;
//�ݹ���ĺ������ж��ַ����Ƿ�Գ� 
bool testPalindrome(vector<char>a,int x,int y,int s)
{
   if((y+1) == s && a[0] == a[s-1])
   return 1;
   else
   return (a[x] == a[y]) && testPalindrome(a,x - 1,y + 1,s); 	
}

int main()
{
	//ʹ��string[]Ҳ���� 
	//���ַ����洢�ڶ�̬�ַ������� 
	vector<char>a;
	char ch;
	while(true)
	{
		ch = getchar();
		if(ch == '\n')
		break;
		a.push_back(ch);
	}
	//����м�ԳƵ������±�x,y 
	int s = a.size();
	int x,y;
	if(s % 2 != 0)
	{
	    x = s/2-1;
	    y = s/2+2-1;	
	}
	else if(s % 2 == 0)
	{
		x = s/2-1;
		y = s/2+1-1;
	}
	
	cout << testPalindrome(a,x,y,s);
	return 0;
}
