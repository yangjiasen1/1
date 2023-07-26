/*
  FileName:T7_26.cpp
  Author:yangjiasen
  E-mail:2462980372@qq.com
  Time:Apr 25th,2022
  College:School of Computer Science and Information Engineeering
*/
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
using namespace std;

const int s = 8;//����ĳ���
//��ӡarray���� 
void printArray(array<array<int,s>,s>a)
{
	for(int i = 0;i<a.size();i++)
	{
		for(int j = 0;j<a[s].size();j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
//�жϵ�ǰ�Ƿ�����ƶ� 
bool canMove(array<array<int,s>,s>a,int row,int column)
{
	return row>=0&&row<s&&column>=0&&column<s&&a[row][column] == 0;
}

bool canMove1(array<array<int,s>,s>a,int row,int column)
{
	return row>=0&&row<s&&column>=0&&column<s;
}
int main()
{
	//��ʼ������Ϊ0 
	array<array<int,s>,s>board = {0};
	printArray(board);
	array<array<int,s>,s>access = 
	{
		2, 3, 4, 4, 4, 4, 3, 2,
        3, 4, 6, 6, 6, 6, 4, 3,
        4, 6, 8, 8, 8, 8, 6, 4,
        4, 6, 8, 8, 8, 8, 6, 4,
        4, 6, 8, 8, 8, 8, 6, 4,
        4, 6, 8, 8, 8, 8, 6, 4,
        3, 4, 6, 6, 6, 6, 4, 3,
        2, 3, 4, 4, 4, 4, 3, 2
	};
	//�ƶ���ʽ 
	array<int,s>horizontal = {2,1,-1,-2,-2,-1,1,2};
	array<int,s>vertical = {-1,-2,-2,-1,1,2,2,1};
	int m;
	bool p;
	
	bool q = true;//�Ƿ��ܼ����ƶ� 
	
	int minRow,minCol; // ����ŵ�ʱͨ��access�ȽϺ�Ľ�С�ģ����ѣ���Ѳ�η�ʽ 
	int minAccess=9; // ��������ҵ���С��access�����е�ֵ
	int accessNumber; 
	
	int currentRow,currentColumn;//��¼��ǰλ�� 
	int testRow,testColumn;//���Կ���λ�� 
	srand((int)time(NULL));
	currentRow = rand() % 8;
	currentColumn = rand() % 8;
	int moveNumber = 1;//�ƶ����� 
	board[currentRow][currentColumn] = moveNumber;
	
	while(q)
	{
		accessNumber=minAccess;
		//ѭ�����������ƶ���ʽ���ҳ�Ŀ���ƶ���ʽ 
		for(m = 0;m<s;m++)
		{
		testRow = currentRow + vertical[m];
		testColumn = currentColumn + horizontal[m];
		p = canMove(board,testRow,testColumn);
		
		if(p)
		{
			if(access[testRow][testColumn]<accessNumber)
				{
					accessNumber=access[testRow][testColumn];
					minRow=testRow;
					minCol=testColumn;
				}
				access[testRow][testColumn]--;
			
		}
		}
		if(accessNumber==minAccess)
			q = false;
		else
		{
			currentRow=minRow;
			currentColumn=minCol;
			board[currentRow][currentColumn]=++moveNumber; 
		}
		
	}
	for(m = 0;m<s;m++)
		{
		testRow = currentRow + vertical[m];
		testColumn = currentColumn + horizontal[m];
        p = canMove1(board,testRow,testColumn);
		
		if(p)
		{
			if(access[testRow][testColumn]<accessNumber)
				{
					accessNumber=access[testRow][testColumn];
					minRow=testRow;
					minCol=testColumn;
				}
				access[testRow][testColumn]--;
			
		}
		}
		if(accessNumber==minAccess)
			q = false;
		else
		{
			currentRow=minRow;
			currentColumn=minCol;
			board[currentRow][currentColumn]=++moveNumber; 
		}
		
			printArray(board);
		bool w = true;	
		for(int i = 0;i<=12;i++)
		{
			for(int j = 0;j<=12;j++)
			{
				if(board[i][j] == 1)
				{
					w = false;
					break;
				}
			}
			if(!w)
			break;
		}
	if(w)
	cout << "��һ����յ�Ѳ��" << endl; 
	else
	cout << "����һ����յ�Ѳ��" << endl;

	return 0;
}


