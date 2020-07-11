#include<stdio.h>
#include<stdlib.h>


#define NULL 0
#define ERROR 0

//以有向网为例
#define INFINITY 32767//最大值：假定为无穷大
#define MAX_VERTEX_NUM 10//最大顶点数目

typedef int VRType;//顶点关系类型，对于无权图或网，用0或1表示相邻否；对于带权图或网，则为相应权值
typedef int VertexType;//顶点类型
typedef VRType AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	AdjMatrix arcs;//邻接矩阵
	int vexnum, arcnum;//图的当前顶点数和弧数
	//GraphKind kind;//图的种类标志
}MGraph;//邻接矩阵表示的图

//若图G中存在顶点v，则返回v在图中的位置信息，否则返回其他信息
int locateVex(MGraph G, VertexType v){
	for(int i = 0; i < G.vexnum; i++){
		if(G.vexs[i] == v)
			return i;
	}
	return -1;//图中没有该顶点
}
//采用邻接矩阵表示法构造有向网G
void createDN(MGraph &G){
	printf("输入顶点数和弧数如:(5,3):");
	scanf("%d,%d", &G.vexnum, &G.arcnum);
 
	//构造顶点向量
	printf("输入%d个顶点（以空格隔开如：v1 v2 v3）:", G.vexnum);
	getchar();//吃掉换行符
	for(int m = 0; m < G.vexnum; m++){
		scanf("v%d", &G.vexs[m]);
		getchar();//吃掉空格符
	}
 
	
	//初始化邻接矩阵
	int i=0, j=0;
	for(i = 0; i < G.vexnum; i++){
		for(j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = INFINITY;
	}
 
	//构造邻接矩阵
	VertexType v1, v2;//分别是一条弧的弧尾和弧头（起点和终点）
	VRType w;//对于无权图或网，用0或1表示相邻否；对于带权图或网，则为相应权值	
	printf("\n每行输入一条弧依附的顶点（先弧尾后弧头）和权值（如：v1 v2 3）:\n");
	fflush(stdin);//清除残余后，后面再读入时不会出错
	for(int k = 0; k < G.arcnum; k++){
		scanf("v%d v%d %d",&v1, &v2, &w);
		fflush(stdin);//清除残余后，后面再读入时不会出错
		i = locateVex(G, v1);
		j = locateVex(G, v2);
		G.arcs[i][j] = w;
	}
}
//打印邻接矩阵
void printDN(MGraph G){
	printf("\n打印有向网G的邻接矩阵：\n");
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
	int adjvex;//该弧所指向的顶点的在图中位置
	VRType w;//弧的相应权值
	struct ArcNode *nextarc;//指向下一条弧的指针
}ArcNode;//弧结点信息
 
typedef struct VNode{
	VertexType data;//顶点信息
	ArcNode *firstarc;//指向第一条依附该顶点的弧的指针
}VNode, AdjVexList[MAX_VERTEX_NUM];//顶点结点信息
 
typedef struct{
	AdjVexList vexs;//顶点向量
	int vexnum, arcnum;//图的当前顶点数和弧数
	//GraphKind kind;//图的种类标志
}ALGraph;//邻接表表示的图
//若图G中存在顶点v，则返回v在图中的位置信息，否则返回其他信息
int locateVex(ALGraph G, VertexType v){
	for(int i = 0; i < G.vexnum; i++){
		if(G.vexs[i].data == v)
			return i;
	}
	return -1;//图中没有该顶点
}
//采用邻接表表示法构造无向网G
void createUDN(ALGraph &G){
	printf("输入顶点数和弧数如:(5,3):");
	scanf("%d,%d", &G.vexnum, &G.arcnum);
 
	//构造顶点向量,并初始化
	printf("输入%d个顶点（以空格隔开如：v1 v2 v3）:", G.vexnum);
	getchar();//吃掉换行符
	for(int m = 0; m < G.vexnum; m++){
		scanf("v%d", &G.vexs[m].data);
		G.vexs[m].firstarc = NULL;//初始化为空指针////////////////重要！！！
		getchar();//吃掉空格符
	}
 
	//构造邻接表
	VertexType v1, v2;//分别是一条弧的弧尾和弧头（起点和终点）
	VRType w;//对于无权图或网，用0或1表示相邻否；对于带权图或网，则为相应权值	
	printf("\n每行输入一条弧依附的顶点（先弧尾后弧头）和权值（如：v1 v2 3）:\n");
	fflush(stdin);//清除残余后，后面再读入时不会出错
	int i = 0, j = 0;
	for(int k = 0; k < G.arcnum; k++){
		scanf("v%d v%d %d",&v1, &v2, &w);
		fflush(stdin);//清除残余后，后面再读入时不会出错
		i = locateVex(G, v1);//弧起点
		j = locateVex(G, v2);//弧终点
		
		//采用"头插法"在各个顶点的弧链头部插入弧结点
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));//构造一个弧结点，作为弧vivj的弧头（终点）
		p1->adjvex = j;
		p1->w = w;
		p1->nextarc = G.vexs[i].firstarc;
		G.vexs[i].firstarc = p1;
		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));//构造一个弧结点，作为弧vivj的弧尾（起点）
		p2->adjvex = i;
		p2->w = w;
		p2->nextarc = G.vexs[j].firstarc;
		G.vexs[j].firstarc = p2;
	}
}
//打印邻接表
void printAdjList(ALGraph G){
	printf("\n");
	for(int i = 0; i < G.vexnum; i++){
		printf("依附顶点v%d的弧为：", G.vexs[i].data);
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

int LocalBow(char data,total *G)				//查询顶点的位置
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

void create(total *G)							//创建十字链表
{
	char x,y;int k,j,i;
	printf("请输入图的顶点和弧的数量：");
	scanf("%d %d",&G->peak,&G->edge);
	for(i=0;i<G->peak;i++)
	{
		fflush(stdin);
		printf("请输入第%d个顶点的值:",i+1);
		scanf("%c",&G->list[i].data);
		G->list[i].firIn=G->list[i].firOut=NULL;
	}
	for(i=0;i<G->edge;i++)
	{
	    fflush(stdin);
		printf("请输入<vi,vj>，中间用英文逗号隔开：");
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
		printf("%c顶点出度情况为：\n",G.list[i].data);
		t=G.list[i].firOut;
		if(!t)	printf("无");
		while(t)
		{
			printf("%c->%c ",t->head,t->tail);
			t=t->tlink;
		}
		printf("\n");
		t=G.list[i].firIn;
		printf("%c顶点入度情况为：\n",G.list[i].data);
		if(!t)		printf("无");
		while(t)
		{
			printf("%c->%c ",t->head,t->tail);
			t=t->hlink;
		 }
		 printf("\n");
	}
}



typedef struct ArcNode1{	
	int ivex, jvex;//该边所依附的2个顶点的在图中位置
	struct ArcNode1 *ivexNextarc, *jvexNextarc;//分别指向该边所依附的两个顶点下一条边
}ArcNode1;//弧结点信息
 
typedef struct VNode1{
	VertexType data;//顶点信息
	ArcNode1 *firstedge;//指向第一条依附该顶点的弧的指针
}VNode1, AdjMuitiVexList[MAX_VERTEX_NUM];//顶点结点信息
 
typedef struct{
	AdjMuitiVexList vexs;//顶点向量
	int vexnum, arcnum;//图的当前顶点数和弧数
	//GraphKind kind;//图的种类标志
}AMLGraph;//邻接表表示的图
//若图G中存在顶点v，则返回v在图中的位置信息，否则返回其他信息
int locateVex(AMLGraph G, VertexType v){
	for(int i = 0; i < G.vexnum; i++){
		if(G.vexs[i].data == v)
			return i;
	}
	return -1;//图中没有该顶点
}
//采用邻接多重表表示法构造无向图G
void createUDG(AMLGraph &G){
	printf("输入顶点数和弧数如:(5,3):");
	scanf("%d,%d", &G.vexnum, &G.arcnum);
 
	//构造顶点向量,并初始化
	printf("输入%d个顶点（以空格隔开如：v1 v2 v3）:", G.vexnum);
	getchar();//吃掉换行符
	for(int m = 0; m < G.vexnum; m++){
		scanf("v%d", &G.vexs[m].data);
		G.vexs[m].firstedge = NULL;//初始化为空指针////////////////重要！！！
		getchar();//吃掉空格符
	}
 
	//构造邻接多重表
	VertexType v1, v2;//分别是一条的两个顶点
	printf("\n每行输入一条边依附的顶点（如：v1v2）:\n");
	fflush(stdin);//清除残余后，后面再读入时不会出错
	int i = 0, j = 0;
	for(int k = 0; k < G.arcnum; k++){
		scanf("v%dv%d",&v1, &v2);
		fflush(stdin);//清除残余后，后面再读入时不会出错
		i = locateVex(G, v1);//边依附的两个顶点的在图中的位置
		j = locateVex(G, v2);
		
		//采用"头插法"在各个顶点的边链头部插入边结点
		ArcNode1 *p = (ArcNode1 *)malloc(sizeof(ArcNode1));//构造一个边结点，它依附于vivj两个顶点
		p->ivex = i;
		p->ivexNextarc = G.vexs[i].firstedge;
		G.vexs[i].firstedge = p;
		p->jvex = j;
		p->jvexNextarc = G.vexs[j].firstedge;
		G.vexs[j].firstedge = p;
	}
}
//打印邻接多重表
void printAdjMultiList(AMLGraph G){
	printf("\n");
	for(int i = 0; i < G.vexnum; i++){
		printf("依附顶点v%d的边为：", G.vexs[i].data);
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

