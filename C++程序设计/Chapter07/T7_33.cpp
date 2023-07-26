/*
  FileName:T7_33.cpp
  Author:yangjiasen
  E-mail:2462980372@qq.com
  Time:Apr 25th,2022
  College:School of Computer Science and Information Engineeering
*/
#include <iostream>
using namespace std;

char ch[12][12] =
{
	{'#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#','.','.','.','#','#','.','.','.','.','.','#'},
	{'.','.','#','.','#','#','.','#','#','#','.','#'},
	{'#','#','#','.','#','#','.','.','.','#','.','#'},
	{'#','.','.','.','.','#','#','#','.','#','.','.'},	
	{'#','#','#','#','.','#','.','#','.','#','.','#'},
	{'#','.','.','#','.','#','.','#','.','#','.','#'},
	{'#','#','.','#','.','#','.','#','.','#','.','#'},
	{'#','.','.','.','.','.','.','.','.','#','.','#'},
	{'#','#','#','#','#','#','.','#','#','#','.','#'},
	{'#','.','.','.','.','.','.','#','.','.','.','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#'}
}; 
//��ʾx�ĵ�ǰ�ƶ�״�� 
void disp(int m,int n)
{
	cout << endl;
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			if(i==m&&j==n){
				cout << "x" << " ";
			}
			else
			{
				cout << ch[i][j] << " ";
			}
		}
		cout << endl;
	}
}
//�ݹ麯���ҵ��Թ����� 
void mazeTraverse(int d,int first=0,int m = 2 ,int n = 0 )
{
	//ÿ���ƶ���ʾ�Թ���x��λ��
	disp(m,n);
	
	//�����ǳ�ʼ̽Ѱ�����ж��Ƿ񵽴��Թ��߽�
	if(!first&&(m==0||m==11||n==0||n==11))
			return;
	
	//������ǰ�ߣ���������ǽ�����򲻱� 
	// ������ǰ�ߣ�������ûǽ����ʱ��ǰ�ߣ���������ת 
	//�����ߣ���ת 
	switch(d)
	{
		case 0:	//����
			if(ch[m-1][n]=='.'&&ch[m-1][n+1]=='#')   //��������ֱ��
			{
				mazeTraverse(d,0,m-1,n);
				return; 
			} 
			//���������ߣ�������֮������ûǽ 
			else if(ch[m-1][n]=='.'&&ch[m-1][n+1]!='#')
			{			
				mazeTraverse(3,0,m-1,n);
				return;
			}
			// �����ߣ�����ת 
			else										
				mazeTraverse(2,0,m,n);
			break; 
		case 1: //��������
			//��������ֱ��
			if(ch[m+1][n]=='.'&&ch[m+1][n-1]=='#')   
			{
				mazeTraverse(d,0,m+1,n);
				return; 
			}
			//���������ߵ�����ûǽ������ת
			else if(ch[m+1][n]=='.'&&ch[m+1][n-1]!='#')
			{	
				mazeTraverse(2,0,m+1,n);
				return;
			}
			// �����ߣ�����ת 
			else											
				mazeTraverse(3,0,m,n);
			break;	
		case 2: //����
			//��������ֱ��
			if(ch[m][n-1]=='.'&&ch[m-1][n-1]=='#')   
			{
				mazeTraverse(d,0,m,n-1);
				return; 
			}
			//���������ߵ�����ûǽ������ת 
			else if(ch[m][n-1]=='.'&&ch[m-1][n-1]!='#')
			{	
				mazeTraverse(0,0,m,n-1);
				return;
			}
			// �����ߣ�����ת 
			else											
				mazeTraverse(1,0,m,n);
			break;
		case 3: //����
			//��������ֱ��
			if(ch[m][n+1]=='.'&&ch[m+1][n+1]=='#')   
			{
				mazeTraverse(d,0,m,n+1);
				return; 
			}
			//���������ߵ�����ûǽ������ת
			else if(ch[m][n+1]=='.'&&ch[m+1][n+1]!='#')
			{	
				mazeTraverse(1,0,m,n+1);
				return;
			}
			// �����ߣ�����ת 
			else												
				mazeTraverse(0,0,m,n);
			break;
	} 
} 

int main()
{
	mazeTraverse(3,1,2,0); 
	return 0;
}

