/*
  FileName:T7_27.cpp
  Author:yangjiasen
  E-mail:2462980372@qq.com
  Time:Apr 25th,2022
  College:School of Computer Science and Information Engineeering
*/
#include <iostream>
#include <array>
using namespace std;

int main()
{
    int i; 
    //������ȫ����ʼ��Ϊ1 
    array<int,1000>a = {0};
    for(i=2;i<=1000;i++)
    {
        a[i]=1;
    }
    //���±��б�����ϵ�����޸�Ϊ0 
    for(i=2;i<=1000;i++)
    {
        for(int c=i*2;c<=1000;c+=i)
        {
            a[c]=0;
        }
    }
    //������� 
    cout<<"1000���ڵ�����Ϊ��"<<endl;
    for(i=2;i<=1000;i++)
    {
        if(a[i])
        cout<<i<<" ";
    }
    return 0;
}

