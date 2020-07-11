#include<stdio.h>
#include<stdlib.h>


#define NULL 0
#define ERROR 0

//��������Ϊ��
#define INFINITY 32767//���ֵ���ٶ�Ϊ�����
#define MAX_VERTEX_NUM 10//��󶥵���Ŀ

typedef int VRType;//�����ϵ���ͣ�������Ȩͼ��������0��1��ʾ���ڷ񣻶��ڴ�Ȩͼ��������Ϊ��ӦȨֵ
typedef int VertexType;//��������
typedef VRType AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix arcs;//�ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
	//GraphKind kind;//ͼ�������־
}MGraph;//�ڽӾ����ʾ��ͼ

//��ͼG�д��ڶ���v���򷵻�v��ͼ�е�λ����Ϣ�����򷵻�������Ϣ
int locateVex(MGraph G, VertexType v){
	for(int i = 0; i < G.vexnum; i++){
		if(G.vexs[i] == v)
			return i;
	}
	return -1;//ͼ��û�иö���
}
//�����ڽӾ����ʾ������������G
void createDN(MGraph &G){
	printf("���붥�����ͻ�����:(5,3):");
	scanf("%d,%d", &G.vexnum, &G.arcnum);
 
	//���춥������
	printf("����%d�����㣨�Կո�����磺v1 v2 v3��:", G.vexnum);
	getchar();//�Ե����з�
	for(int m = 0; m < G.vexnum; m++){
		scanf("v%d", &G.vexs[m]);
		getchar();//�Ե��ո��
	}
 
	
	//��ʼ���ڽӾ���
	int i=0, j=0;
	for(i = 0; i < G.vexnum; i++){
		for(j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = INFINITY;
	}
 
	//�����ڽӾ���
	VertexType v1, v2;//�ֱ���һ�����Ļ�β�ͻ�ͷ�������յ㣩
	VRType w;//������Ȩͼ��������0��1��ʾ���ڷ񣻶��ڴ�Ȩͼ��������Ϊ��ӦȨֵ	
	printf("\nÿ������һ���������Ķ��㣨�Ȼ�β��ͷ����Ȩֵ���磺v1 v2 3��:\n");
	fflush(stdin);//�������󣬺����ٶ���ʱ�������
	for(int k = 0; k < G.arcnum; k++){
		scanf("v%d v%d %d",&v1, &v2, &w);
		fflush(stdin);//�������󣬺����ٶ���ʱ�������
		i = locateVex(G, v1);
		j = locateVex(G, v2);
		G.arcs[i][j] = w;
	}
}
//��ӡ�ڽӾ���
void printDN(MGraph G){
	printf("\n��ӡ������G���ڽӾ���\n");
	for(int i = 0; i < G.vexnum; i++){
		for(int j = 0; j < G.vexnum; j++)
		{
			if(G.arcs[i][j] != INFINITY)
				printf("%9d ", G.arcs[i][j]);
			else
				printf("INFINITY  ");
		}
		printf("\n");
	}
	printf("\n");
}

void Array(){
	MGraph G;
	createDN(G);	
	printDN(G);
}

typedef struct ArcNode{	
	int adjvex;//�û���ָ��Ķ������ͼ��λ��
	VRType w;//������ӦȨֵ
	struct ArcNode *nextarc;//ָ����һ������ָ��
}ArcNode;//�������Ϣ
 
typedef struct VNode{
	VertexType data;//������Ϣ
	ArcNode *firstarc;//ָ���һ�������ö���Ļ���ָ��
}VNode, AdjVexList[MAX_VERTEX_NUM];//��������Ϣ
 
typedef struct{
	AdjVexList vexs;//��������
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
	//GraphKind kind;//ͼ�������־
}ALGraph;//�ڽӱ��ʾ��ͼ
//��ͼG�д��ڶ���v���򷵻�v��ͼ�е�λ����Ϣ�����򷵻�������Ϣ
int locateVex(ALGraph G, VertexType v){
	for(int i = 0; i < G.vexnum; i++){
		if(G.vexs[i].data == v)
			return i;
	}
	return -1;//ͼ��û�иö���
}
//�����ڽӱ��ʾ������������G
void createUDN(ALGraph &G){
	printf("���붥�����ͻ�����:(5,3):");
	scanf("%d,%d", &G.vexnum, &G.arcnum);
 
	//���춥������,����ʼ��
	printf("����%d�����㣨�Կո�����磺v1 v2 v3��:", G.vexnum);
	getchar();//�Ե����з�
	for(int m = 0; m < G.vexnum; m++){
		scanf("v%d", &G.vexs[m].data);
		G.vexs[m].firstarc = NULL;//��ʼ��Ϊ��ָ��////////////////��Ҫ������
		getchar();//�Ե��ո��
	}
 
	//�����ڽӱ�
	VertexType v1, v2;//�ֱ���һ�����Ļ�β�ͻ�ͷ�������յ㣩
	VRType w;//������Ȩͼ��������0��1��ʾ���ڷ񣻶��ڴ�Ȩͼ��������Ϊ��ӦȨֵ	
	printf("\nÿ������һ���������Ķ��㣨�Ȼ�β��ͷ����Ȩֵ���磺v1 v2 3��:\n");
	fflush(stdin);//�������󣬺����ٶ���ʱ�������
	int i = 0, j = 0;
	for(int k = 0; k < G.arcnum; k++){
		scanf("v%d v%d %d",&v1, &v2, &w);
		fflush(stdin);//�������󣬺����ٶ���ʱ�������
		i = locateVex(G, v1);//�����
		j = locateVex(G, v2);//���յ�
		
		//����"ͷ�巨"�ڸ�������Ļ���ͷ�����뻡���
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));//����һ������㣬��Ϊ��vivj�Ļ�ͷ���յ㣩
		p1->adjvex = j;
		p1->w = w;
		p1->nextarc = G.vexs[i].firstarc;
		G.vexs[i].firstarc = p1;
		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));//����һ������㣬��Ϊ��vivj�Ļ�β����㣩
		p2->adjvex = i;
		p2->w = w;
		p2->nextarc = G.vexs[j].firstarc;
		G.vexs[j].firstarc = p2;
	}
}
//��ӡ�ڽӱ�
void printAdjList(ALGraph G){
	printf("\n");
	for(int i = 0; i < G.vexnum; i++){
		printf("��������v%d�Ļ�Ϊ��", G.vexs[i].data);
		ArcNode *p = G.vexs[i].firstarc;
		while(p){
			printf("v%dv%d(weight:%d) ", G.vexs[i].data, G.vexs[p->adjvex].data, p->w);
			p = p->nextarc;
		}
		printf("\n");
	}
	printf("\n");
}
void AdjacencyList(){
	ALGraph G;
	createUDN(G);
	printAdjList(G);
}


typedef struct  Bow
{
	char head,tail;

	struct Bow *hlink,*tlink;
}Bow;

typedef struct FirstNode
{
	char data;

	Bow *firIn;
	Bow *firOut;
}FirstNode;

typedef struct
{
	FirstNode list[100];

	int peak,edge;
}total;

int LocalBow(char data,total *G)				//��ѯ�����λ��
{
	int i;
	for(i=0;i<G->peak;i++)
	{
		if(G->list[i].data==data)
		{
			return i;
		}
	}
	return ERROR;
}

void create(total *G)							//����ʮ������
{
	char x,y;int k,j,i;
	printf("������ͼ�Ķ���ͻ���������");
	scanf("%d %d",&G->peak,&G->edge);
	for(i=0;i<G->peak;i++)
	{
		fflush(stdin);
		printf("�������%d�������ֵ:",i+1);
		scanf("%c",&G->list[i].data);
		G->list[i].firIn=G->list[i].firOut=NULL;
	}
	for(i=0;i<G->edge;i++)
	{
	    fflush(stdin);
		printf("������<vi,vj>���м���Ӣ�Ķ��Ÿ�����");
		scanf("%c,%c",&x,&y);

		Bow *R=(Bow *)malloc(sizeof(Bow));
		k=LocalBow(x,G);
		j=LocalBow(y,G);
		R->head=x;
		R->tail=y;
		R->hlink=G->list[j].firIn;
		R->tlink=G->list[k].firOut;
		G->list[j].firIn=R;
		G->list[k].firOut=R;
	}
}
void CurbTable()
{
	total G;
	Bow *t;
	create(&G);
	int i;
	for(i=0;i<G.peak;i++)
	{
		printf("%c����������Ϊ��\n",G.list[i].data);
		t=G.list[i].firOut;
		if(!t)	printf("��");
		while(t)
		{
			printf("%c->%c ",t->head,t->tail);
			t=t->tlink;
		}
		printf("\n");
		t=G.list[i].firIn;
		printf("%c����������Ϊ��\n",G.list[i].data);
		if(!t)		printf("��");
		while(t)
		{
			printf("%c->%c ",t->head,t->tail);
			t=t->hlink;
		 }
		 printf("\n");
	}
}



typedef struct ArcNode1{	
	int ivex, jvex;//�ñ���������2���������ͼ��λ��
	struct ArcNode1 *ivexNextarc, *jvexNextarc;//�ֱ�ָ��ñ�������������������һ����
}ArcNode1;//�������Ϣ
 
typedef struct VNode1{
	VertexType data;//������Ϣ
	ArcNode1 *firstedge;//ָ���һ�������ö���Ļ���ָ��
}VNode1, AdjMuitiVexList[MAX_VERTEX_NUM];//��������Ϣ
 
typedef struct{
	AdjMuitiVexList vexs;//��������
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
	//GraphKind kind;//ͼ�������־
}AMLGraph;//�ڽӱ��ʾ��ͼ
//��ͼG�д��ڶ���v���򷵻�v��ͼ�е�λ����Ϣ�����򷵻�������Ϣ
int locateVex(AMLGraph G, VertexType v){
	for(int i = 0; i < G.vexnum; i++){
		if(G.vexs[i].data == v)
			return i;
	}
	return -1;//ͼ��û�иö���
}
//�����ڽӶ��ر��ʾ����������ͼG
void createUDG(AMLGraph &G){
	printf("���붥�����ͻ�����:(5,3):");
	scanf("%d,%d", &G.vexnum, &G.arcnum);
 
	//���춥������,����ʼ��
	printf("����%d�����㣨�Կո�����磺v1 v2 v3��:", G.vexnum);
	getchar();//�Ե����з�
	for(int m = 0; m < G.vexnum; m++){
		scanf("v%d", &G.vexs[m].data);
		G.vexs[m].firstedge = NULL;//��ʼ��Ϊ��ָ��////////////////��Ҫ������
		getchar();//�Ե��ո��
	}
 
	//�����ڽӶ��ر�
	VertexType v1, v2;//�ֱ���һ������������
	printf("\nÿ������һ���������Ķ��㣨�磺v1v2��:\n");
	fflush(stdin);//�������󣬺����ٶ���ʱ�������
	int i = 0, j = 0;
	for(int k = 0; k < G.arcnum; k++){
		scanf("v%dv%d",&v1, &v2);
		fflush(stdin);//�������󣬺����ٶ���ʱ�������
		i = locateVex(G, v1);//�������������������ͼ�е�λ��
		j = locateVex(G, v2);
		
		//����"ͷ�巨"�ڸ�������ı���ͷ������߽��
		ArcNode1 *p = (ArcNode1 *)malloc(sizeof(ArcNode1));//����һ���߽�㣬��������vivj��������
		p->ivex = i;
		p->ivexNextarc = G.vexs[i].firstedge;
		G.vexs[i].firstedge = p;
		p->jvex = j;
		p->jvexNextarc = G.vexs[j].firstedge;
		G.vexs[j].firstedge = p;
	}
}
//��ӡ�ڽӶ��ر�
void printAdjMultiList(AMLGraph G){
	printf("\n");
	for(int i = 0; i < G.vexnum; i++){
		printf("��������v%d�ı�Ϊ��", G.vexs[i].data);
		ArcNode1 *p = G.vexs[i].firstedge;
 
		while(p){
			if(p->ivex == i){
				printf("v%dv%d ", G.vexs[i].data, G.vexs[p->jvex].data);
				p = p->ivexNextarc;
			}else if(p->jvex == i){
				printf("v%dv%d ", G.vexs[i].data, G.vexs[p->ivex].data);
				p = p->jvexNextarc;
			}
		}
		printf("\n");
	}
	printf("\n");
}

void AdjacentMultipleTables(){
	AMLGraph G;
	createUDG(G);
	printAdjMultiList(G);
}

