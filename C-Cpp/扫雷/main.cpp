#include "header.h"

void loadimage_game();

void gameinit();  //��Ϸ��ʼ��

void game();   //��Ϸ����

int playgame();

//void openzero(int r,int c);


int main()				//��������
{

	HWND hwnd=initgraph(ROW*SIZE,COL*SIZE,SHOWCONSOLE);		//��һ������

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
			MessageBox(hwnd,"\t��!!!","",MB_OK);
			break;
		}
		if (ROW*COL-NULL==count)
		{
			game();
			MessageBox(hwnd,"\tţ��!!!","",MB_OK);
			break;
		}
	}
	
	closegraph();
	
	
	return 0;
}



/***************************************
�����׵ķֲ�ȥ��䲻Ϊ�׵�����
1�������Ź���
2��tip�����ϵ����ݱ���ʱ��Խ��
3������һ���������������Ϊ����������Ϸ����
  **************************************/

/***********************
	Ԫ��      ͼƬ
	0��6       img[0-6]  
	��			img[10]
**/