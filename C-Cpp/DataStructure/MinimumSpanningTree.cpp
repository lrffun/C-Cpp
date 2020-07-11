#include <stdio.h>
#define x 10000
const int NumVertex = 7;
const int NumEdge = 12;

 
int hash[NumVertex];//节点所属的集合
int Edge[NumEdge];//按照邻接表的排列顺序给每条边编号，该数组表示图中第i条边的长度
int BeginVertex[NumEdge], EndVertex[NumEdge];//图中边的起始节点和图中边的终止节点
int AcceptedEdge[NumEdge];//每条边被接受的情况，接受为1，不接受为0
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
 
int distance[NumVertex] = { x, x, x, x, x, x, x };//第i个节点到已知节点的最小权值
int path[NumVertex];//导致第i个节点距离变化的最后一个顶点
int Known[NumVertex];//节点访问情况


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
		}                                    //寻找距离最短的节点
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
				}                           //更新距离
 
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
	printf("Prim算法执行结果：\n");
	Prim(0, map);
	printarray(distance);
	printf("\n");
	printarray(path);
	printf("\n");
}


 
 int Find(int Vertex)
{
	return hash[Vertex];
}//查找节点所属的集合
 
void Union(int Vertex1, int Vertex2)
{
	for (int i = 0; i < NumVertex; i++)
	{
		if (hash[i] == hash[Vertex2])
			hash[i] = hash[Vertex1];
	}
}//合并两个节点
 
void Kruskal(int map[][NumVertex])
{
	int EdgeOrder = 0;
 
    for (int i = 0; i < NumVertex; i++)
	{
		hash[i] = i + 1;
	}//散列函数，返回节点所属的集合
 
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
	}//存储边的信息，长度，起点，终点
 
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
		}//搜索距离最小的边
 
		Known[position] = 1;//标记该变已经被访问过
 
		if (Find(BeginVertex[position]) != Find(EndVertex[position]))
		{
			Union(BeginVertex[position], EndVertex[position]);
			AcceptedEdge[position] = 1;
		}//如果选取的边加到图中没有构成圈（两节点属于不同集合），则该边可以接受，遂把该边加入图中
	}
}
 

 
void Kruskal()
{
	printf("Kruskal算法执行结果：\n");
	Kruskal(map);
	printarray1(AcceptedEdge);
	printf("\n");
	printarray1(BeginVertex);
	printf("\n");
	printarray1(EndVertex);
	printf("\n");
}
