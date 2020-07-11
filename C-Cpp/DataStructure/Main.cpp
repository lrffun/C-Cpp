#include<stdio.h>
#include<stdlib.h>
#include "storage.cpp"
#include "traverse.cpp"
#include "MinimumSpanningTree.cpp"
#include "TopologicalSort.cpp"
#include "ShortestPath.cpp"
#include "Example.cpp"

void start(){
	printf("\n\n\n\n\t\t\t\t***********************************************************\n\n");
	printf("\t\t\t\t                 欢迎来到数据结构学习平台                  \n\n");
	printf("\t\t\t\t                   请选择你要学习的内容                  \n\n");
	printf("\t\t\t\t                    1. 图的基本概念\n\n");
	printf("\t\t\t\t                    2. 图的存储\n\n");
	printf("\t\t\t\t                    3. 图的遍历\n\n");
	printf("\t\t\t\t                    4. 最小生成树\n\n");
	printf("\t\t\t\t                    5. 拓扑排序和关键路径\n\n");
	printf("\t\t\t\t                    6. 最短路径\n\n");
	printf("\t\t\t\t                    7. 图的算法应用举例\n\n");
	printf("\t\t\t\t                    0. 退出系统\n\n");
	printf("\t\t\t\t***********************************************************\n");

}

void con1(){
	int input = -1;
	system("cls");
	printf("\n\n\n\n\t\t\t\t***********************************************************\n");
	printf("\t\t\t\t                     图的基本概念\n\n");
	printf("\t\t\t\t                    0. 返回\n");
	printf("\t\t\t\t                    1. 图的定义\n");
	printf("\t\t\t\t                    2. 有向图\n");
	printf("\t\t\t\t                    3. 无向图\n");
	printf("\t\t\t\t                    4. 简单图\n");
	printf("\t\t\t\t                    5. 完全图\n");
	printf("\t\t\t\t                    6. 子图\n");
	printf("\t\t\t\t                    7. 连通、连通图和连通分量\n");
	printf("\t\t\t\t                    8. 强连通图、强连通分量\n");
	printf("\t\t\t\t                    9. 生成树和生成森林\n");
	printf("\t\t\t\t                    10. 顶点的度、入度和出度\n");
	printf("\t\t\t\t                    11. 边的权和网\n");
	printf("\t\t\t\t                    12. 路径、路径长度和回路\n");
	printf("\t\t\t\t                    13. 简单路径、简单回路\n");
	printf("\t\t\t\t                    14. 距离\n");
	printf("\t\t\t\t                    15. 有向树\n");
	printf("\n\n\n\n\t\t\t\t***********************************************************\n");
	scanf("%d",&input);
	switch(input){					//选择功能
		case 0:break;
		case 1:system("cls");printf("\n\n图的定义：\n图G由顶点集V和边集E组成，记为G=(V,E)，其中V(G)表示图G中顶点的有限非空集；E(G)表示图G中顶点之间的关系(边)的集合。\n");break;
		case 2:system("cls");printf("\n\n有向图：\n若E是有向边（简称弧）的有限集合时，则G为有向图。弧是顶点的有序对，记为<v,w>，其中 v，w 是顶点，v 是弧尾，w 是弧头。称为从顶点v到顶点w的弧。\n");break;
		case 3:system("cls");printf("\n\n无向图：\n若E是无向边（简称边）的有限集合时，则G为无向图。边是顶点的无序对，记为 (v,w) 或(w,v) ，且有 (v,w) =(w,v) 。其中 v，w 是顶点。\n");break;
		case 4:system("cls");printf("\n\n简单图:\n简单图满足以下两条内容：\n1）不存在重复边\n2）不存在顶点到自身的边\n");break;
		case 5:system("cls");printf("\n\n完全图:\n无向图中任意两点之间都存在边，称为无向完全图；如无向图中的示例就是完全图。\n有向图中任意两点之间都存在方向向反的两条弧，称为有向完全图。\n");break;
		case 6:system("cls");printf("\n\n子图：\n若有两个图G=(V,E),G1=(V1,E2)，若V1是V的子集且E2是E的子集，称G1是G的子图。\n");break;
		case 7:system("cls");printf("\n\n连通、连通图、连通分量：\n在无向图中，两顶点有路径存在，就称为连通的。若图中任意两顶点都连通，同此图为连通图。无向图中的极大连通子图称为连通分量。\n");break;
		case 8:system("cls");printf("\n\n强连通图、强连通分量：\n在有向图中，两顶点两个方向都有路径，两顶点称为强连通。若任一顶点都是强连通的，称为强连通。有向图中极大强连通子图为有向图的强连通分量。\n");break;
		case 9:system("cls");printf("\n\n生成树和生成森林：\n连通图的生成树是包含图中全部顶点的一个极小连通子图，若图中有n个顶点，则生成树有n-1条边。所以对于生成树而言，若砍去一条边，就会变成非连通图。\n");break;
		case 10:system("cls");printf("\n\n顶点的度、入度和出度：\n顶点的度为以该顶点为一个端点的边的数目。\n对于无向图，顶点的边数为度，度数之和是顶点边数的两倍。\n对于有向图，入度是以顶点为终点，出度相反。有向图的全部顶点入度之和等于出度之和且等于边数。顶点的度等于入度与出度之和。\n注意：入度与出度是针对有向图来说的。\n");break;
		case 11:system("cls");printf("\n\n边的权和网：\n图中每条边上标有某种含义的数值，该数值称为该边的权值。这种图称为带树图，也称作网。\n");break;
		case 12:system("cls");printf("\n\n路径、路径长度和回路：\n两顶点之间的路径指顶点之间经过的顶点序列，经过路径上边的数目称为路径长度。若有n个顶点，且边数大于n-1，此图一定有环。\n");break;
		case 13:system("cls");printf("\n\n简单路径、简单回路：\n顶点不重复出现的路径称为简单路径。\n除第一个顶点和最后一个顶点外，其余顶点不重复出现的回路称为简单回路。\n");break;
		case 14:system("cls");printf("\n\n距离：\n若两顶点存在路径，其中最短路径长度为距离。\n");break;
		case 15:system("cls");printf("\n\n有向树：\n有一个顶点的入度为0，其余顶点的入度均为1的有向图称作有向树。\n");break;
		default:break;
	}
	system("pause");
	if(input){con1();}
}

void con2(){
	system("cls");
	int input = -1;
	printf("\n\n\n\n\t\t\t\t***********************************************************\n\n");
	printf("\t\t\t\t		    欢迎来到图的存储章节                \n\n");
	printf("\t\t\t\t                   请选择你要测试的存储方法                  \n\n");
	printf("\t\t\t\t                    1. 数组表示\n\n");
	printf("\t\t\t\t                    2. 邻接表\n\n");
	printf("\t\t\t\t                    3. 十字链表\n\n");
	printf("\t\t\t\t                    4. 邻接多重表\n\n");
	printf("\t\t\t\t                    0. 返回上一级\n\n");
	printf("\t\t\t\t***********************************************************\n");
	scanf("%d",&input);
	switch(input){					//选择功能
		case 0:break;
		case 1:system("cls");Array();break;
		case 2:system("cls");AdjacencyList();break;
		case 3:system("cls");CurbTable();break;
		case 4:system("cls");AdjacentMultipleTables();break;
		default:break;
	}
	if(input){con2();}
}

void con3(){
	system("cls");
	traverse();
}

void printMap(){
	printf("图的结构如下：\n");
	for(int q = 0;q < 7;q++){
		for(int w = 0;w < 7;w++){
			if(map[q][w]==10000){
				printf("x\t");
			}else{
				printf("%d\t",map[q][w]);
			}
		}
		printf("\n");
	}
} 

void con4(){
	int input = -1;
	system("cls");
	printf("\n\n\n\n\t\t\t\t***********************************************************\n\n");
	printf("\t\t\t\t			欢迎来到最小生成树章节                \n\n");
	printf("\t\t\t\t                   请选择你要测试的求最小生成树方法                  \n\n\n");
	printf("\t\t\t\t                    0. 返回\n\n");
	printf("\t\t\t\t                    1. Prim算法\n\n");
	printf("\t\t\t\t                    2. Kruskal算法\n\n");
	printf("\t\t\t\t***********************************************************\n");
	scanf("%d",&input);
	switch(input){					//选择功能
		case 0:break;
		case 1:system("cls");printMap();Prim();break;
		case 2:system("cls");printMap();Kruskal();break;
		default:break;
	}
	system("pause");
	if(input){con4();}
}

void con5(){
	system("cls");
	topologicalSort();
}

void con6(){
	system("cls");
	printf("详情见代码，输出最短路径：");
	shortestPath();
	printf("\n");
	system("pause");
}

void con7(){
	system("cls");
	example();
	system("pause");
}

int main(void){
	system("color 1f"); 
	int input = -1;
	while(input){
		system("cls");
		start();
		scanf("%d",&input);
		switch(input){					//选择功能
			case 0:break;
			case 1:con1();break;
			case 2:con2();break;
			case 3:con3();break;
			case 4:con4();break;
			case 5:con5();break;
			case 6:con6();break;
			case 7:con7();break;
			default:break;
		}
	}
	
	return 0;
}