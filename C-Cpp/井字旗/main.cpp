/*
��Ϸ���ƣ�������
���ߣ������
����ʱ�䣺2019��5��5��
  */

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

IMAGE img;

int a[3][3] = { {0,0,0},
				{0,0,0},
				{0,0,0}};							//������Ϸ������

int r,s,count=0,test=0,test2=0;					//��ʼ��Intֵ

MOUSEMSG m;												//����һ�������Ϣ

HWND hwnd;												//����һ�����ھ��

void drawback();												//����������

void loadimg();													//����ͼƬ����

void putimg();												//���ͼƬ����

void str();															//��Ϸ���̺���

void gameover();												//�ж���Ϸ�������

// void printtest();												//������Ϸ��(��Ϸ������)

int main(void)
{
	hwnd=initgraph(470,470);			//��ʼ��һ�����������ھ����Ϊhwnd

	loadimg();							//��ͼƬ�������ڴ���

	drawback();							//��������
	
	str();								//��Ϸ��ʼ

	return 0;
}

void drawback()
{
	BeginBatchDraw();													//��ʼ����ͼ��

	setfillcolor(RGB(70,70,70));									//���ñ�����ɫ

	solidrectangle(0,0,470,470);									//��һ�����α���

	for (int i=151;i<160;i++)										//��������for����Ϸ�еķָ���
	{
		setcolor(WHITE);

		line(i,0,i,470);

		line(0,i,470,i);
	}

	for (int j=311;j<320;j++)
	{
		setcolor(WHITE);

		line(j,0,j,470);

		line(0,j,470,j);
	}

	FlushBatchDraw();											//�������۵�ͼƬ

	EndBatchDraw();												//��������
}

void loadimg()
{
	loadimage(&img,"img.jpg",480,800);									//����ͼƬ
}

void putimg()
{
	for (int m=0;m<3;m++)
	{
		for (int n=0;n<3;n++)
		{
			if (a[m][n]==-1)
			{
				putimage(m*160,n*160,150,150,&img,330,74);				//�����
			}
			if (a[m][n]==1)
			{
				putimage(m*160,n*160,150,150,&img,8,235);				//�����
			}
		}
	}
	
}

void str()
{

	while(1)
	{		
		test2=0;

		gameover();

	//	if (MouseHit())
	//	{
			m=GetMouseMsg();															//���������Ϣ

			if (m.uMsg==WM_LBUTTONDOWN)
			{
				if (m.x>=150&&m.x<=160||m.x>=310&&m.x<=320||m.y>=150&&m.y<=160||m.y>=310&&m.y<=320)   //�ų��㵽�ָ��ߵ����
				{
					continue;
				}
				else
				{
					r=(m.x-20)/150;														//�ҵ����λ�ö�Ӧ��������ĸ�����
					s=(m.y-20)/150;
				}
				count++;
				if (count%2!=0)															//����if������ڵ�һ�λ�һ�������
				{
					a[r][s]=1;
				}
				else
				{
					a[r][s]=-1;
				}
			}
			if (m.uMsg==WM_RBUTTONDOWN)														//����Ҽ���������˳���Ϸ
			{
				break;
			}
	//	}
		
	//	printtest();

		putimg();																	//����ͼƬ

		gameover();																		//�ж��Ƿ�����Ӯ
	
		for (int w=0;w<3;w++)														//�ж��Ƿ�ƽ��
		{
			for (int e=0;e<3;e++)
			{
				if (a[w][e]!=0)
				{
					test2++;
				}
				if (test2==9)
				{
					MessageBox(hwnd,"ƽ�֣�","",MB_OK);
					break;
				}								
			}
		}
		if (test!=0||test2==9)														//�������Ӯ����ƽ�֣�����Ϸ����������ѭ��
		{
			break;
		}
	}
	
}

void gameover()
{
	if (a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[0][0]==a[1][1])						//�ж��Ƿ���б����ͬ
	{
		test=a[0][0];
	}

	if (a[2][0]==a[1][1]&&a[2][0]==a[0][2]&&a[1][1]==a[0][2])	
	{
		test=a[2][0];
	}

	for (int q=0;q<3;q++)																//�ж��Ƿ��к�����ͬ
	{
		if (a[q][0]==a[q][1]&&a[q][0]==a[q][2]&&a[q][1]==a[q][2])		
		{
			test=a[q][0];
			break;
		}
	}

	for (int p=0;p<3;p++)																//�ж��Ƿ���������ͬ
	{	
		if (a[0][p]==a[1][p]&&a[0][p]==a[2][p]&&a[1][p]==a[2][p])
		{
			test=a[0][p]; 
			break;
		}
	}
	
	if (test==1)																		//�������ͬ�Ҳ�Ϊ�㣬����˭Ӯ
	{
		MessageBox(hwnd,"p1ʤ��","",MB_OK);
	}
	if (test==-1)
	{
		MessageBox(hwnd,"p2ʤ��","",MB_OK);													//��Ϸ����
	}
}

// void printtest()
// {
// 	system("cls");
// 
// 	for (int z=0;z<3;z++)
// 	{
// 		for (int x=0;x<3;x++)
// 		{
// 			printf("%d\t",a[z][x]);
// 		}
// 		printf("\n");
// 	}
// }