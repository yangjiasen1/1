/*
  FileName:T4_13.cpp
  Author:yangjiasen
  E-mail:2462980372@qq.com
  Time:Mar 17th,2022
 */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    double mile,tmile=0,aver;
    int gallons,tgallons;
    cout <<"�����뱾�������:";
    cin>>mile;
    cout<<setprecision(6)<<fixed;
    while(mile!=EOF)
    {
        cout<<"�����뱾��ʹ�õ����ͼ���:";
        cin>>gallons;
        aver=mile/static_cast<double>(gallons);
        cout<<"���κ������Ч��:"<<aver<<endl;
        tmile=tmile+mile;
        tgallons=tgallons+gallons;
        cout<<"�ܺ������Ч��:"<<tmile/static_cast<double>(tgallons)<<endl;
        cout<<"�����뱾�������:";
        cin>>mile;

    }
    return 0;
}
