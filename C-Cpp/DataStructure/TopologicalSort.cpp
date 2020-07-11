#define _CRT_SECURE_NO_WARNINGS 1
 
 
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<string.h>
 
 
 
 
 
 
 
#define MaxVernum 20  //����ͼ��󶥵���Ŀ
 
#define STACK_INIT_SIZE 10                                      //�洢�ռ��ʼ������
 
#define STACKINCREMENT 2   //�洢�ռ��������
 
int degree[MaxVernum];
 
typedef int SElemType;
 
typedef char VertexType5;
 
 
 
//�洢ͼ�ı�
 
typedef struct ArcNode5
 
{
 
SElemType Ver;//�洢����ָ��Ķ���
 
SElemType Weight;//�洢�ñߵ�Ȩ��
 
struct ArcNode5 *next;//ָ����һ���ߵ�ָ����
 
}ArcNode5;
 
 
 
//�洢ͼ�Ķ���
 
typedef struct VerNode
 
{
 
VertexType5 data[20];//�洢�ö��������
 
struct ArcNode5 *firstArc;// �ߵ�ͷָ��
 
SElemType indegree;//�ý������
 
SElemType flag;//�趨һ����־���ں����ж����·����һ�����Ƕ���
 
}VerNode, AdjList[MaxVernum];
 
 
 
//�洢ͼ
 
typedef struct
 
{
 
AdjList adjlist;
 
SElemType Arcnum;//�洢ͼ�еıߵ���Ŀ
 
SElemType Vernum;//�洢ͼ�еĶ������Ŀ
 
}ALGraph5;
 
 
 
 
 
//ջ��˳��洢�ṹ��ʾ
 
typedef struct SqStack
 
{
 
SElemType *base;                        //ջ�׵�ַ
 
SElemType *top;                         //ջ��ָ��
 
int stacksize;                          //��ǰ�Ѿ�����Ĵ洢�ռ�
 
}SqStack;
 
 
 
//����һ����ջ
 
int InitStack(SqStack &S)
 
{
 
//Ϊջ�׷ַ���һ��ָ����С�Ĵ洢�ռ�
 
(S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
 
if (!(S).base)
 
exit(0);
 
(S).top = (S).base;                   //ջ����ջ��ָ����ͬ
 
(S).stacksize = STACK_INIT_SIZE;
 
return 1;
 
}
 
 
 
 
 
 
 
//��ջSΪ��ջ��ջ��ָ���ջ��ָ����ͬ��, �򷵻�1�����򷵻�0
 
int StackEmpty(SqStack S)
 
{
 
if (S.top == S.base)
 
return 1;
 
else
 
return 0;
 
}
 
 
 
 
 
//����Ԫ��eΪ�µ�ջ��Ԫ��
 
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
 
 
 
 
 
 
 
 
 
//��ջ��Ϊ�գ���ɾ��Sջ��Ԫ����e������ֵ��������1�����򷵻�0
 
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
 
//printf("��%d�����㼴%c���Ϊ:%d\n", j + 1, G->adjlist[j].data, degree[j]);
 
}
 
}
 
//����ͼ��G�����ڽӱ�洢�ṹ����G�޻�·�������G�Ķ����һ�����˽ṹ
 
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
 
Push(&S, i);//�����Ϊ��Ľڵ�ѹջ
 
}
 
printf("������������:\n");
 
while (!StackEmpty(S))//ֻҪջ���ǿյľ�һֱ����
 
{
 
Pop(&S, i);//ջ���ǿյ��Ǿͽ���ߵ�һ����ջȻ�����
 
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
 
 
 
printf("����������ͼ���ڻ���������������");
 
return 0;
 
}
 
printf("\n");
 
return 0;
 
}
 
 
 
 
 
int IfArc(ALGraph5 *G, char *a)//����û��ٴ����붥���Ƿ���ͼ��
 
{
 
int i = 0;
 
for (i = 0; i < G->Vernum; i++)
 
{
 
if (!strcmp(a, G->adjlist[i].data))
 
return i;//�������Ķ����ͼ��ĳһ������ֵ��ͬ���ظö�����ͼ�е�λ�ã�return i֮��Ͳ�����ִ�к���֮�������
 
}
 
return -1;//���forѭ������֮��û���ҵ���Ӧ��ֵ��ô��������ֵΪ-1
 
 
 
}
 
//���캯�� ����ͼ
 
void CreateALGraph5(ALGraph5 *G)
 
{
 
char v1[20];
 
char v2[20];
 
int i = 0;
 
int w = 0;
 
int m = 0;
 
int n = 0;
 
ArcNode5 *p;
 
printf("�����������齨ͼ�Ķ��������ͻ�������:\n");
 
scanf("%d %d", &G->Vernum, &G->Arcnum);
 
for (i = 0; i < G->Vernum; i++)//��ʼ��ͼ�еĶ�����Ϣ
 
{
 
fflush(stdin);//��ջ��������⽫��һ���Ŀո�س�����Ϣ����
 
printf("�������%d������", i + 1);
 
scanf("%s", &G->adjlist[i].data);//�����ж������ݽ��г�ʼ��
 
G->adjlist[i].firstArc = NULL;//��ÿ�������ͷָ�룬�Լ���ȳ�ʼ��
 
G->adjlist[i].flag = 0;
 
G->adjlist[i].indegree = 0;
 
 
 
}
 
system("cls");
 
for (i = 0; i < G->Arcnum; i++)//��ʼ��ͼ�еĻ�����Ϣ
 
{
 
fflush(stdin);
 
printf("�������������Լ�֮���Ȩ��(v1,v2,w):\n");
 
printf("a%d:", i + 1);
 
scanf("%s %s %d", &v1, &v2, &w);
 
m = IfArc(G, v1);
 
n = IfArc(G, v2);
 
if (m == -1 || n == -1)//ֻҪ�����κ�һ�����㲻��ͼ��Ҫ����������
 
{
 
i = i - 1;//��Ϊ����������ݴ������Խ�i��ȥ1��������ѭ������
 
printf("���붥�����ݴ�������������\n");//���������Ϣ
 
continue;//��������ѭ�����ٶԱߵ��������ݽ��в���
 
}
 
p = (ArcNode5*)malloc(sizeof(ArcNode5));//��p���пռ�������Ĵ�С��һ��ArcNode5�ṹ��Ĵ�С
 
p->Ver = n;//������Ϣ
 
p->Weight = w;//Ȩ����Ϣ
 
p->next = G->adjlist[m].firstArc;//���ո����������������������
 
G->adjlist[m].firstArc = p;
 
G->adjlist[n].indegree++;
 
}
 
system("cls");
 
 
 
}
 
 
 
//��ؼ�·�����ؼ������
 
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
 
Vl = (int *)malloc(sizeof(int)*G->Arcnum);//��������������ڴ�ռ䣬��Arcnum����һ����ռint��С���ֽ�
 
memset(Ve, 0, G->Arcnum);
 
memset(Vl, 0, G->Arcnum);//������������г�ʼ��
 
InitStack(S);
 
InitStack(T);
 
Finedegree(G);
 
for (i = 0; i<G->Vernum; i++)
 
{
 
if (!degree[i])
 
Push(&S, i);//�����Ϊ��Ľڵ�ѹջ
 
}
 
printf("������������:\n");
 
while (!StackEmpty(S))//ֻҪջ���ǿյľ�һֱ����
 
{
 
Pop(&S, i);//ջ���ǿյ��Ǿͽ���ߵ�һ����ջȻ�����
 
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
 
if (Ve[i] + p->Weight>Ve[k])//���ǰ�������翪ʼʱ�����Ȩ�ش��ں�������翪ʼʱ��
 
Ve[k] = Ve[i] + p->Weight;//��ô�ͰѺ���Ŀ�ʼʱ�任��ǰ����ʱ���Ȩ��
 
 
 
 
 
}
 
}
 
if (count < G->Vernum)
 
{
 
printf("����������ͼ���ڻ���������������\n");
 
return;
 
}
 
 
 
printf("\n");
 
for (i = 0; i < G->Vernum; i++)
 
{
 
Vl[i] = Ve[G->Vernum - 1];
 
}//����õ����翪ʼʱ��浽����ʼʱ�������
 
 
 
while (!StackEmpty(T))
 
 
 
for (Pop(&T, i), p = G->adjlist[i].firstArc; p; p = p->next)
 
{
 
k = p->Ver;//Ϊ�˻�õ�ǰ������ͼ�е�λ�����洢���翪ʼʱ��
 
if (Vl[k] - p->Weight < Vl[i])//���������ʱ���еļ�ȥ��Ӧ��Ȩ��֮������緢��ʱ��ҪС
 
Vl[i] = Vl[k] - p->Weight;//��Ҫ��������ʱ������滻
 
}
 
 
 
 
 
 
 
 
 
for (i = 0; i < G->Vernum; i++)
 
for (p = G->adjlist[i].firstArc; p; p = p->next)
 
{
 
k = p->Ver;
 
e = Ve[i];
 
l = Vl[k] - p->Weight;//��ÿ��������緢��ʱ���������ʱ�䲢�����
 
printf("����%s �붥��%s  ������緢��ʱ��Ϊ%d  ���������ʱ��Ϊ%d\n", G->adjlist[i].data, G->adjlist[k].data, e, l);
 
 
 
}
 
printf("\n");
 
printf("�ù������Ϊ%s\n",first);
 
printf("�ù����յ�Ϊ%s\n", end);
 
printf("\n");
 
for (i = 0; i < G->Vernum; i++)
 
{
 
p = G->adjlist[i].firstArc;
 
while (p)
 
{
 
k = p->Ver;
 
e = Ve[i];
 
l = Vl[k] - p->Weight;
 
if (e == l)//�����ͬ���ǹؼ��
 
{
 
G->adjlist[i].flag++;//����Ѿ���������´��������Ҫ������
 
if (G->adjlist[i].flag == 1)
 
{
 
spend = spend + p->Weight;
 
printf("(�ؼ��Ϊ%s------>%s  ·������Ϊ%d)\n",  G->adjlist[i].data, G->adjlist[k].data, p->Weight);
 
}
 
else
 
{
 
G->adjlist[k].flag++;
 
if (G->adjlist[i].flag > max)
 
{
 
 
 
max = G->adjlist[i].flag + 1;
 
}
 
printf("(��%d���ؼ��Ϊ%s------>%s  ·������Ϊ%d)\n", G->adjlist[i].flag, G->adjlist[i].data, G->adjlist[k].data, p->Weight);
 
}
 
 
 
}
 
p = p->next;
 
}
 
}
 
printf("\n");
 
printf("���ι��̹���%d���ؼ�·��\n", max);
 
printf("\n");
 
printf("���ι��̻��ѵ�����ʱ��Ϊ:%d\n", spend);
 
printf("\n");
 
 
 
}
 
void menu()
{
 
	printf("\n\n\n\n\t\t\t\t***********************************************************\n\n");
	printf("\t\t\t\t			��ӭ������������͹ؼ�·���½�                \n\n");
	printf("\t\t\t\t                   ��ѡ����Ҫ���Ե�����                 \n\n\n");
	printf("\t\t\t\t                    0. ����\n\n");
	printf("\t\t\t\t                    1. ��������\n\n");
	printf("\t\t\t\t                    2. �ؼ�·��\n\n");
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
 
printf("�����������������\n");
 
break;
 
}
 
menu();
 
scanf("%d", &set);
 
}
 
 
 
system("pause");
 
 
}
