#include <graphics.h>
#include <conio.h>
#pragma comment (lib,"winmm.lib")
#include <MMSYSTEM.H>

IMAGE img[2];

IMAGE text[2];

void loadimg();

void putimg();

void str();

void out_text();

int test[21][21] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

int r=10,s=10,a=1;

MOUSEMSG m;

HWND hwnd;

int main(void)
{
	loadimg();														//加载图片

	hwnd=initgraph(525,525);									//初始化一个画布
	
	str();

	MessageBox(hwnd,"就像纣王爱妲己，宁负天下不负你","",MB_OK);

	out_text();

	system("pause");	

	return 0;
}

void loadimg()
{
	loadimage(&img[0],"back.png",25,25);
	loadimage(&img[1],"xin.jpg",525,525);
}

void putimg()
{

	for (int i=0;i<21;i++)
	{
		for (int j=0;j<21;j++)
		{
			if (test[i][j]==0)
			{putimage(25*i,25*j,&img[0]);}
			if (test[i][j]==1)
			{putimage(25*i,25*j,25,25,&img[1],25*i,25*j);}
						
		}
	}
	
}

void str()
{
	while(1)
	{
		putimg();
		
		if (MouseHit())
		{
			m=GetMouseMsg();
			if (m.uMsg==WM_LBUTTONDOWN)
			{
				
				if (m.x>=250&&m.x<=275&&m.y>=250&&m.y<=275)
				{
					mciSendString("open music.mp3 alias music",0,0,0);
					mciSendString("play music",0,0,0);
					test[r][s]=1;
					while(a<11)
					{
						for (int m=r-a;m<=r+a;m++)
						{
							for (int n=s-a;n<=s+a;n++)
							{
								
								test[m][n]=1;
								putimg();
								Sleep(10);
							}
						}
						a++;
					}
					break;
				}
				else
				{
					MessageBox(hwnd,"请点击正中间！","我接受！",MB_OK);
				}
			}
		}
		
	}
}


void out_text()
{
	settextcolor(RED);

	setbkcolor(WHITE);

	settextstyle(80,0,"楷体",100,100,100,true,false,false);

	outtextxy(50,20,"杨");

	Sleep(1500);

	outtextxy(220,20,"秋");

	Sleep(1500);

	outtextxy(390,20,"霜");

	Sleep(1500);

	outtextxy(80,440,"我");

	Sleep(1500);

	outtextxy(250,440,"爱");

	Sleep(1500);

	outtextxy(400,440,"你");

}