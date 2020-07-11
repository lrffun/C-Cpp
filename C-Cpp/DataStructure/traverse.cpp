#include <stdio.h>
#include <stdlib.h>
#include <graphics.h> 
#include <windows.h>                      
#include <shellapi.h> 

#define maxsize 100
 
typedef struct ArcNode2 {
    int num;
    struct ArcNode2 *next;
}ArcNode2;
typedef struct VNode2{
    ArcNode2 *firstarc;
}VNode2;
typedef struct Graph {
    VNode2 VNode2List[maxsize];
    int n,e;
}Graph;
 
void bulidGraph(Graph *&g);
 
int visitdfs[maxsize];
void DFS(Graph *g ,int v);
void dfs(Graph *g);
 
int visit[maxsize];
void bfs(Graph *g);
void BFS(Graph *g ,int v);
void outputPicture();
 
void traverse()
{
	int inp = -1;
	printf("\t\t\t\t\n\n\n\n请选择：1.深度优先遍历。2.广度优先遍历。0.返回\n");
	scanf("%d",&inp);
	switch(inp){
		case 0:break;
		case 1:Graph *g;g=(Graph *) malloc(sizeof(Graph));bulidGraph(g);outputPicture();printf("该图的深度优先遍历结果为：");dfs(g);break;
		case 2:Graph *k;k=(Graph *) malloc(sizeof(Graph));bulidGraph(k);outputPicture();printf("该图的广度优先遍历结果为：");bfs(k);break;
		default:break;
	}
	if(inp){
		traverse();
	}
}
 
void outputPicture(){
	 ShellExecute( NULL, _T("open"), _T("travese.png"), NULL, NULL, SW_SHOWNORMAL ); 
}

void DFS(Graph *g ,int v){
    ArcNode2 *p=g->VNode2List[v].firstarc;
    visitdfs[v]=1;
    printf("%d",v);
    while (p!=NULL){
        if(visitdfs[p->num]==0)
        DFS(g,p->num);
        p=p->next;
    }
}
void dfs(Graph *g){
    for(int i=0;i<g->n;i++){
        if(visitdfs[i]==0)
            DFS(g,i);
    }
}
 
void BFS(Graph *g,int v){
    ArcNode2 *p ;
    int que [maxsize], top=0,rear=0;
    int j;
    printf("%d",v);
    visit[v]=1;
    rear =(rear+1)%maxsize;
    que[rear]=v;
    while(top!=rear){
        top =(top+1)%maxsize;
        j=que[top];
        p=g->VNode2List[j].firstarc;
        while (p!=NULL){
            if(visit[p->num]==0){
                printf("%d",p->num);
                visit[p->num]=1;
                rear=(rear+1)%maxsize;
                que[rear]=p->num;
 
                }
                p=p->next;
        }
    }
}
void bfs(Graph *g){
    for(int i=0;i<g->n;i++){
        if(visit[i]==0)
            BFS(g,i);
    }
}
 
void bulidGraph(Graph *&g){
    g->n=6;
    g->e=7;
 
    VNode2 v0,v1 ,v2, v3 ,v4 ,v5,v6;
    ArcNode2 *v01,*v03,*v04,*v14,*v12,*v20,*v32,*v56;
 
    v01=(ArcNode2 *) malloc(sizeof(ArcNode2));
    v01->num=1;
    v03=(ArcNode2 *) malloc(sizeof(ArcNode2));
    v03->num=3;
    v04=(ArcNode2 *) malloc(sizeof(ArcNode2));
    v04->num=4;
    v14=(ArcNode2 *) malloc(sizeof(ArcNode2));
    v14->num=4;
    v12=(ArcNode2 *) malloc(sizeof(ArcNode2));
    v12->num=2;
    v20=(ArcNode2 *) malloc(sizeof(ArcNode2));
    v20->num=0;
    v32=(ArcNode2 *) malloc(sizeof(ArcNode2));
    v32->num=2;
    v56=(ArcNode2 *) malloc(sizeof(ArcNode2));
    v56->num=6;
 
    v0.firstarc=v01;
    v1.firstarc=v14;
    v2.firstarc=v20;
    v3.firstarc=v32;
    v4.firstarc=NULL;
    v5.firstarc=v56;
    v6.firstarc=NULL;
 
    v01->next=v03;
    v03->next=v04;
    v14->next=v12;
    v32->next=NULL;
    v20->next=NULL;
    v12->next=NULL;
    v04->next=NULL;
    v56->next=NULL;
 
    g->VNode2List[0]=v0;
    g->VNode2List[1]=v1;
    g->VNode2List[2]=v2;
    g->VNode2List[3]=v3;
    g->VNode2List[4]=v4;
    g->VNode2List[5]=v5;
    g->VNode2List[6]=v6;
 
}
