/*
游戏名称：井字旗
作者：郎瑞峰
创作时间：2019年5月5日
  */

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

IMAGE img;

int a[3][3] = { {0,0,0},
				{0,0,0},
				{0,0,0}};							//定义游戏的数组

int r,s,count=0,test=0,test2=0;					//初始化Int值

MOUSEMSG m;												//定义一个鼠标消息

HWND hwnd;												//定义一个窗口句柄

void drawback();												//画背景函数

void loadimg();													//加载图片函数

void putimg();												//输出图片函数

void str();															//游戏过程函数

void gameover();												//判断游戏结果函数

// void printtest();												//调试游戏用(游戏中无用)

int main(void)
{
	hwnd=initgraph(470,470);			//初始化一个画布，窗口句柄设为hwnd

	loadimg();							//将图片加载至内存中

	drawback();							//画出背景
	
	str();								//游戏开始

	return 0;
}

void drawback()
{
	BeginBatchDraw();													//开始积累图画

	setfillcolor(RGB(70,70,70));									//设置背景颜色

	solidrectangle(0,0,470,470);									//画一个矩形背景

	for (int i=151;i<160;i++)										//以下两个for画游戏中的分割线
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

	FlushBatchDraw();											//画出积累的图片

	EndBatchDraw();												//结束积累
}

void loadimg()
{
	loadimage(&img,"img.jpg",480,800);									//加载图片
}

void putimg()
{
	for (int m=0;m<3;m++)
	{
		for (int n=0;n<3;n++)
		{
			if (a[m][n]==-1)
			{
				putimage(m*160,n*160,150,150,&img,330,74);				//输出×
			}
			if (a[m][n]==1)
			{
				putimage(m*160,n*160,150,150,&img,8,235);				//输出○
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
			m=GetMouseMsg();															//接收鼠标消息

			if (m.uMsg==WM_LBUTTONDOWN)
			{
				if (m.x>=150&&m.x<=160||m.x>=310&&m.x<=320||m.y>=150&&m.y<=160||m.y>=310&&m.y<=320)   //排除点到分割线的情况
				{
					continue;
				}
				else
				{
					r=(m.x-20)/150;														//找到点击位置对应在数组的哪个数上
					s=(m.y-20)/150;
				}
				count++;
				if (count%2!=0)															//以下if语句用于点一次换一个×或○
				{
					a[r][s]=1;
				}
				else
				{
					a[r][s]=-1;
				}
			}
			if (m.uMsg==WM_RBUTTONDOWN)														//如果右键点击，则退出游戏
			{
				break;
			}
	//	}
		
	//	printtest();

		putimg();																	//画出图片

		gameover();																		//判断是否有输赢
	
		for (int w=0;w<3;w++)														//判断是否平局
		{
			for (int e=0;e<3;e++)
			{
				if (a[w][e]!=0)
				{
					test2++;
				}
				if (test2==9)
				{
					MessageBox(hwnd,"平局！","",MB_OK);
					break;
				}								
			}
		}
		if (test!=0||test2==9)														//如果有输赢或者平局，则游戏结束，跳出循环
		{
			break;
		}
	}
	
}

void gameover()
{
	if (a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[0][0]==a[1][1])						//判断是否有斜向相同
	{
		test=a[0][0];
	}

	if (a[2][0]==a[1][1]&&a[2][0]==a[0][2]&&a[1][1]==a[0][2])	
	{
		test=a[2][0];
	}

	for (int q=0;q<3;q++)																//判断是否有横向相同
	{
		if (a[q][0]==a[q][1]&&a[q][0]==a[q][2]&&a[q][1]==a[q][2])		
		{
			test=a[q][0];
			break;
		}
	}

	for (int p=0;p<3;p++)																//判断是否有纵向相同
	{	
		if (a[0][p]==a[1][p]&&a[0][p]==a[2][p]&&a[1][p]==a[2][p])
		{
			test=a[0][p]; 
			break;
		}
	}
	
	if (test==1)																		//如果有相同且不为零，弹出谁赢
	{
		MessageBox(hwnd,"p1胜！","",MB_OK);
	}
	if (test==-1)
	{
		MessageBox(hwnd,"p2胜！","",MB_OK);													//游戏结束
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