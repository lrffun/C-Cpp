#include <stdio.h>
#define x 10000
const int NumVertex = 7;
const int NumEdge = 12;

 
int hash[NumVertex];//�ڵ������ļ���
int Edge[NumEdge];//�����ڽӱ������˳���ÿ���߱�ţ��������ʾͼ�е�i���ߵĳ���
int BeginVertex[NumEdge], EndVertex[NumEdge];//ͼ�бߵ���ʼ�ڵ��ͼ�бߵ���ֹ�ڵ�
int AcceptedEdge[NumEdge];//ÿ���߱����ܵ����������Ϊ1��������Ϊ0
int Known1[NumEdge];

int map[NumVertex][NumVertex] =
  //1  2  3  4  5  6  7
{
	x, 2, 4, 1, x, x, x,  //1
	2, x, x, 3, 10, x, x, //2
	4, x, x, 2, x, x, x,  //3
	1, 3, 2, x, 7, 8, 4,  //4
	x, 10, x, 7, x, x, 6, //5
	x, x, 5, 8, x, x, 1,  //6
	x, x, x, 4, 6, 1, x   //7
};
 
int distance[NumVertex] = { x, x, x, x, x, x, x };//��i���ڵ㵽��֪�ڵ����СȨֵ
int path[NumVertex];//���µ�i���ڵ����仯�����һ������
int Known[NumVertex];//�ڵ�������


void Prim(int Begin, int map[][NumVertex])
{
	distance[Begin] = 0;
 
	for (;;)
	{
		int min = x, position=0;
		for (int i = 0; i<NumVertex;i++)
		{
			if (Known[i]==0&&min>=distance[i])
			{
				min = distance[i];
				position = i;
			}
		}                                    //Ѱ�Ҿ�����̵Ľڵ�
		Known[position] = 1;
 
		if (min == x)
			break;
 
		for (i = 0; i < NumVertex; i++)
		{
			if (map[position][i] != x&&Known[i] == 0)
			{
				if (distance[i]>map[position][i])
				{
					distance[i] = map[position][i];
					path[i] = position+1;
				}                           //���¾���
 
			}
 
		}
	}
}
 
void printarray(int a[])
{
	for (int i = 0; i < NumVertex; i++)
	{
		printf("%d ", a[i]);
	}
}

void printarray1(int array[])
{
	for (int i = 0; i <NumEdge; i++)
		printf("%d ", array[i]);
}
 
void Prim()
{
	printf("Prim�㷨ִ�н����\n");
	Prim(0, map);
	printarray(distance);
	printf("\n");
	printarray(path);
	printf("\n");
}


 
 int Find(int Vertex)
{
	return hash[Vertex];
}//���ҽڵ������ļ���
 
void Union(int Vertex1, int Vertex2)
{
	for (int i = 0; i < NumVertex; i++)
	{
		if (hash[i] == hash[Vertex2])
			hash[i] = hash[Vertex1];
	}
}//�ϲ������ڵ�
 
void Kruskal(int map[][NumVertex])
{
	int EdgeOrder = 0;
 
    for (int i = 0; i < NumVertex; i++)
	{
		hash[i] = i + 1;
	}//ɢ�к��������ؽڵ������ļ���
 
	for (i = 0; i < NumVertex; i++)
	{
		for (int j = i+1; j < NumVertex; j++)
		{
			if (map[i][j]<x)
			{
				Edge[EdgeOrder] = map[i][j];
				BeginVertex[EdgeOrder] = i;
				EndVertex[EdgeOrder] = j;
				EdgeOrder++;
			}
		}
	}//�洢�ߵ���Ϣ�����ȣ���㣬�յ�
 
	for (i = 0; i < NumEdge; i++)
	{
		int min = x, position = -1;
		for (int i = 0; i < NumEdge; i++)
		{
			if (Known1[i] != 1 && min>Edge[i])
			{
 
				min = Edge[i];
				position = i;
			}
		}//����������С�ı�
 
		Known[position] = 1;//��Ǹñ��Ѿ������ʹ�
 
		if (Find(BeginVertex[position]) != Find(EndVertex[position]))
		{
			Union(BeginVertex[position], EndVertex[position]);
			AcceptedEdge[position] = 1;
		}//���ѡȡ�ı߼ӵ�ͼ��û�й���Ȧ�����ڵ����ڲ�ͬ���ϣ�����ñ߿��Խ��ܣ���Ѹñ߼���ͼ��
	}
}
 

 
void Kruskal()
{
	printf("Kruskal�㷨ִ�н����\n");
	Kruskal(map);
	printarray1(AcceptedEdge);
	printf("\n");
	printarray1(BeginVertex);
	printf("\n");
	printarray1(EndVertex);
	printf("\n");
}
