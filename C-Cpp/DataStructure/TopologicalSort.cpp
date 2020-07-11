#define _CRT_SECURE_NO_WARNINGS 1
 
 
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<string.h>
 
 
 
 
 
 
 
#define MaxVernum 20  //定义图最大顶点数目
 
#define STACK_INIT_SIZE 10                                      //存储空间初始分配量
 
#define STACKINCREMENT 2   //存储空间分配增量
 
int degree[MaxVernum];
 
typedef int SElemType;
 
typedef char VertexType5;
 
 
 
//存储图的边
 
typedef struct ArcNode5
 
{
 
SElemType Ver;//存储边所指向的顶点
 
SElemType Weight;//存储该边的权重
 
struct ArcNode5 *next;//指向下一个边的指针结点
 
}ArcNode5;
 
 
 
//存储图的顶点
 
typedef struct VerNode
 
{
 
VertexType5 data[20];//存储该顶点的数据
 
struct ArcNode5 *firstArc;// 边的头指针
 
SElemType indegree;//该结点的入度
 
SElemType flag;//设定一个标志用于后期判断最短路径是一条还是多条
 
}VerNode, AdjList[MaxVernum];
 
 
 
//存储图
 
typedef struct
 
{
 
AdjList adjlist;
 
SElemType Arcnum;//存储图中的边的数目
 
SElemType Vernum;//存储图中的顶点的数目
 
}ALGraph5;
 
 
 
 
 
//栈的顺序存储结构表示
 
typedef struct SqStack
 
{
 
SElemType *base;                        //栈底地址
 
SElemType *top;                         //栈顶指针
 
int stacksize;                          //当前已经分配的存储空间
 
}SqStack;
 
 
 
//构造一个空栈
 
int InitStack(SqStack &S)
 
{
 
//为栈底分分配一个指定大小的存储空间
 
(S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
 
if (!(S).base)
 
exit(0);
 
(S).top = (S).base;                   //栈底与栈顶指针相同
 
(S).stacksize = STACK_INIT_SIZE;
 
return 1;
 
}
 
 
 
 
 
 
 
//若栈S为空栈（栈底指针和栈顶指针相同）, 则返回1，否则返回0
 
int StackEmpty(SqStack S)
 
{
 
if (S.top == S.base)
 
return 1;
 
else
 
return 0;
 
}
 
 
 
 
 
//插入元素e为新的栈顶元素
 
int Push(SqStack *S, SElemType e)
 
{
 
if ((*S).top - (*S).base >= (*S).stacksize)
 
{
 
(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
 
if (!(*S).base)
 
exit(0);
 
(*S).top = (*S).base + (*S).stacksize;
 
(*S).stacksize += STACKINCREMENT;
 
}
 
*((*S).top)++ = e;
 
return 1;
 
}
 
 
 
 
 
 
 
 
 
//若栈不为空，则删除S栈顶元素用e返回其值，并返回1，否则返回0
 
int Pop(SqStack *S, SElemType &e)
 
{
 
if ((*S).top == (*S).base)
 
{
 
return 0;
 
}
 
e = *--(*S).top;
 
return 1;
 
}
 
void Finedegree(ALGraph5 *G)
 
{
 
int j = 0;
 
for (j = 0; j<G->Vernum; j++)
 
{
 
 
 
degree[j] = G->adjlist[j].indegree;
 
//printf("第%d个顶点即%c入度为:%d\n", j + 1, G->adjlist[j].data, degree[j]);
 
}
 
}
 
//有向图的G采用邻接表存储结构，若G无回路，则输出G的顶点的一个拓扑结构
 
int TopologicalSort(ALGraph5 *G)
 
{
 
int i, k;
 
int count = 0;
 
SqStack S;
 
ArcNode5 *p;
 
int e = 0;
 
int j = 0;
 
p = NULL;
 
InitStack(S);
 
Finedegree(G);
 
for (i = 0; i<G->Vernum; i++)
 
{
 
if (!degree[i])
 
Push(&S, i);//把入度为零的节点压栈
 
}
 
printf("拓扑排列如下:\n");
 
while (!StackEmpty(S))//只要栈不是空的就一直进行
 
{
 
Pop(&S, i);//栈不是空的那就将里边的一个出栈然后输出
 
printf("%s", G->adjlist[i].data);
 
count++;
 
for (p = G->adjlist[i].firstArc; p; p = p->next)
 
{
 
k = p->Ver;
 
if (!(--degree[k]))
 
Push(&S, k);
 
 
 
 
 
}
 
}
 
if (count < G->Vernum)
 
{
 
 
 
printf("您所创建的图存在环不可以拓扑排序");
 
return 0;
 
}
 
printf("\n");
 
return 0;
 
}
 
 
 
 
 
int IfArc(ALGraph5 *G, char *a)//检查用户再次输入顶点是否在图中
 
{
 
int i = 0;
 
for (i = 0; i < G->Vernum; i++)
 
{
 
if (!strcmp(a, G->adjlist[i].data))
 
return i;//如果输入的顶点和图中某一顶点数值相同返回该顶点在图中的位置，return i之后就不会再执行函数之后的内容
 
}
 
return -1;//如果for循环结束之后还没有找到对应的值那么函数返回值为-1
 
 
 
}
 
//构造函数 创建图
 
void CreateALGraph5(ALGraph5 *G)
 
{
 
char v1[20];
 
char v2[20];
 
int i = 0;
 
int w = 0;
 
int m = 0;
 
int n = 0;
 
ArcNode5 *p;
 
printf("请输入你想组建图的顶点总数和弧边总数:\n");
 
scanf("%d %d", &G->Vernum, &G->Arcnum);
 
for (i = 0; i < G->Vernum; i++)//初始化图中的顶点信息
 
{
 
fflush(stdin);//清空缓存区以免将上一步的空格回车等信息输入
 
printf("请输入第%d个顶点", i + 1);
 
scanf("%s", &G->adjlist[i].data);//给所有顶点数据进行初始化
 
G->adjlist[i].firstArc = NULL;//将每个顶点的头指针，以及入度初始化
 
G->adjlist[i].flag = 0;
 
G->adjlist[i].indegree = 0;
 
 
 
}
 
system("cls");
 
for (i = 0; i < G->Arcnum; i++)//初始化图中的弧边信息
 
{
 
fflush(stdin);
 
printf("请输入两顶点以及之间的权重(v1,v2,w):\n");
 
printf("a%d:", i + 1);
 
scanf("%s %s %d", &v1, &v2, &w);
 
m = IfArc(G, v1);
 
n = IfArc(G, v2);
 
if (m == -1 || n == -1)//只要其中任何一个顶点不在图中要求重新输入
 
{
 
i = i - 1;//因为这次输入数据错误所以将i减去1，不增加循环次数
 
printf("输入顶点数据错误请重新输入\n");//输出错误信息
 
continue;//跳过本次循环不再对边的其他内容进行操作
 
}
 
p = (ArcNode5*)malloc(sizeof(ArcNode5));//对p进行空间分配分配的大小是一个ArcNode5结构体的大小
 
p->Ver = n;//顶点信息
 
p->Weight = w;//权重信息
 
p->next = G->adjlist[m].firstArc;//将刚刚输入的两个顶点链接起来
 
G->adjlist[m].firstArc = p;
 
G->adjlist[n].indegree++;
 
}
 
system("cls");
 
 
 
}
 
 
 
//求关键路径、关键活动函数
 
void FineCriticalpath(ALGraph5 *G, SqStack &T)
 
{
 
char first[20];
 
char end[20];
 
int sum = 0;
 
int *Ve;
 
int *Vl;
 
int i = 0;
 
int k = 0;
 
int e = 0;
 
int l = 0;
 
int max = 0;
 
int count = 0;
 
int j = 0;
 
int spend = 0;
 
SqStack S;
 
ArcNode5 *p;
 
p = NULL;
 
Ve = (int *)malloc(sizeof(int)*G->Arcnum);
 
Vl = (int *)malloc(sizeof(int)*G->Arcnum);//给两个数组分配内存空间，有Arcnum个边一个边占int大小的字节
 
memset(Ve, 0, G->Arcnum);
 
memset(Vl, 0, G->Arcnum);//对两个数组进行初始化
 
InitStack(S);
 
InitStack(T);
 
Finedegree(G);
 
for (i = 0; i<G->Vernum; i++)
 
{
 
if (!degree[i])
 
Push(&S, i);//把入度为零的节点压栈
 
}
 
printf("拓扑排列如下:\n");
 
while (!StackEmpty(S))//只要栈不是空的就一直进行
 
{
 
Pop(&S, i);//栈不是空的那就将里边的一个出栈然后输出
 
sum++;
 
if (sum==1)
 
strcpy(first, G->adjlist[i].data);
 
if (sum==G->Vernum)
 
strcpy(end, G->adjlist[i].data);  
 
Push(&T, i);
 
printf("%s", G->adjlist[i].data);
 
count++;
 
for (p = G->adjlist[i].firstArc; p; p = p->next)
 
{
 
k = p->Ver;
 
if (!(--degree[k]))
 
Push(&S, k);
 
if (Ve[i] + p->Weight>Ve[k])//如果前结点的最早开始时间加上权重大于后结点的最早开始时间
 
Ve[k] = Ve[i] + p->Weight;//那么就把厚结点的开始时间换成前结点的时间加权重
 
 
 
 
 
}
 
}
 
if (count < G->Vernum)
 
{
 
printf("您所创建的图存在环不可以拓扑排序\n");
 
return;
 
}
 
 
 
printf("\n");
 
for (i = 0; i < G->Vernum; i++)
 
{
 
Vl[i] = Ve[G->Vernum - 1];
 
}//把求得的最早开始时间存到最晚开始时间的数组
 
 
 
while (!StackEmpty(T))
 
 
 
for (Pop(&T, i), p = G->adjlist[i].firstArc; p; p = p->next)
 
{
 
k = p->Ver;//为了获得当前顶点在图中的位置来存储最早开始时间
 
if (Vl[k] - p->Weight < Vl[i])//如果最晚发生时间中的减去相应的权重之后比最早发生时间要小
 
Vl[i] = Vl[k] - p->Weight;//就要将最晚发生时间进行替换
 
}
 
 
 
 
 
 
 
 
 
for (i = 0; i < G->Vernum; i++)
 
for (p = G->adjlist[i].firstArc; p; p = p->next)
 
{
 
k = p->Ver;
 
e = Ve[i];
 
l = Vl[k] - p->Weight;//求每个活动的最早发生时间和最晚发生时间并且输出
 
printf("顶点%s 与顶点%s  活动的最早发生时间为%d  活动的最晚发生时间为%d\n", G->adjlist[i].data, G->adjlist[k].data, e, l);
 
 
 
}
 
printf("\n");
 
printf("该工程起点为%s\n",first);
 
printf("该工程终点为%s\n", end);
 
printf("\n");
 
for (i = 0; i < G->Vernum; i++)
 
{
 
p = G->adjlist[i].firstArc;
 
while (p)
 
{
 
k = p->Ver;
 
e = Ve[i];
 
l = Vl[k] - p->Weight;
 
if (e == l)//如果相同才是关键活动
 
{
 
G->adjlist[i].flag++;//标记已经输出过了下次在输出就要加括号
 
if (G->adjlist[i].flag == 1)
 
{
 
spend = spend + p->Weight;
 
printf("(关键活动为%s------>%s  路径长度为%d)\n",  G->adjlist[i].data, G->adjlist[k].data, p->Weight);
 
}
 
else
 
{
 
G->adjlist[k].flag++;
 
if (G->adjlist[i].flag > max)
 
{
 
 
 
max = G->adjlist[i].flag + 1;
 
}
 
printf("(第%d条关键活动为%s------>%s  路径长度为%d)\n", G->adjlist[i].flag, G->adjlist[i].data, G->adjlist[k].data, p->Weight);
 
}
 
 
 
}
 
p = p->next;
 
}
 
}
 
printf("\n");
 
printf("本次工程共有%d条关键路径\n", max);
 
printf("\n");
 
printf("本次工程花费的最少时间为:%d\n", spend);
 
printf("\n");
 
 
 
}
 
void menu()
{
 
	printf("\n\n\n\n\t\t\t\t***********************************************************\n\n");
	printf("\t\t\t\t			欢迎来到拓扑排序和关键路径章节                \n\n");
	printf("\t\t\t\t                   请选择你要测试的内容                 \n\n\n");
	printf("\t\t\t\t                    0. 返回\n\n");
	printf("\t\t\t\t                    1. 拓扑排序\n\n");
	printf("\t\t\t\t                    2. 关键路径\n\n");
	printf("\t\t\t\t***********************************************************\n");
 
}
 
void  topologicalSort()
 
{
 
int set = 0;
 
ALGraph5 G;
 
SqStack T;
 
menu();
 
scanf("%d", &set);
 
while (set)
 
{
 
switch (set)
 
{
 
 
 
case 1:
 
CreateALGraph5(&G);
 
TopologicalSort(&G);
 
break;
 
 
 
case 2:
 
CreateALGraph5(&G);
 
FineCriticalpath(&G, T);
 
break;
 
default:
 
printf("输入错误请重新输入\n");
 
break;
 
}
 
menu();
 
scanf("%d", &set);
 
}
 
 
 
system("pause");
 
 
}
