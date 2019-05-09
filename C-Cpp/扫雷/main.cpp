#include "header.h"

void loadimage_game();

void gameinit();  //游戏初始化

void game();   //游戏界面

int playgame();

//void openzero(int r,int c);


int main()				//主函数；
{

	HWND hwnd=initgraph(ROW*SIZE,COL*SIZE,SHOWCONSOLE);		//打开一个窗口

	mciSendString("open music.wav alias music",0,0,0);
	mciSendString("play music",0,0,0);

	loadimage_game();

	gameinit();

	

	while(1)
	{
		game();
		
		if(-1==playgame())
		{
			game();
			MessageBox(hwnd,"\t怂!!!","",MB_OK);
			break;
		}
		if (ROW*COL-NULL==count)
		{
			game();
			MessageBox(hwnd,"\t牛逼!!!","",MB_OK);
			break;
		}
	}
	
	closegraph();
	
	
	return 0;
}



/***************************************
根据雷的分布去填充不为雷的数据
1、遍历九宫格
2、tip：边上的数据遍历时会越界
3、加入一个辅助区，将其分为辅助区和游戏区；
  **************************************/

/***********************
	元素      图片
	0—6       img[0-6]  
	雷			img[10]
**/