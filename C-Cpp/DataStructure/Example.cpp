#define MINFINITY 10000 
#define MMAX_VERTEX_NUM 40 
#define MAX 40 
#include<stdlib.h> 
#include<stdio.h> 
#include<conio.h> 
#include<string.h> 
typedef struct ArCell 
{ 
int adj; /*·������ */
}ArCell,MAdjMatrix[MMAX_VERTEX_NUM][MMAX_VERTEX_NUM]; 
typedef struct /*ͼ�ж����ʾ��Ҫ���㣬��ž���ı�š����ơ�������Ϣ�� */
{ 
char name[30]; 
int num; 
char introduction[100];/*���*/ 
}infotype; 
typedef struct 
{ 
infotype vexs[MMAX_VERTEX_NUM]; 
MAdjMatrix arcs; 
int vexnum,arcnum; 
}MMGraph; 
MMGraph b; 

void cmd(void); 
MMGraph InitGraph(void); 
void Menu(void); 
void Browser(MMGraph *G); 
void ShortestPath_DIJ(MMGraph * G); 
void Floyd(MMGraph *G); 
void Search(MMGraph *G); 
int LocateVex(MMGraph *G,char* v); 
MMGraph * CreatUDN(MMGraph *G); 
void print(MMGraph *G); 
/******************************************************/ 
void example(void) 
{ 
system("color 1f"); 
system("mode con: cols=140 lines=130"); 
cmd(); 
} 
/******************************************************/ 

void cmd(void) 
{ 
int i; 
b=InitGraph(); 
Menu(); 
scanf("%d",&i); 
while(i!=5) 
{ 
switch(i) 
{ 
case 1:system("cls");Browser(&b);Menu();break; 
case 2:system("cls");ShortestPath_DIJ(&b);Menu();break; 
case 3:system("cls");Floyd(&b);Menu();break; 
case 4:system("cls");Search(&b);Menu();break; 
case 5:exit(1);break; 
default:break; 
} 

scanf("%d",&i); 
} 
} 
MMGraph InitGraph(void) 
{ 
MMGraph G; 
int i,j; 
G.vexnum=10; 
G.arcnum=14; 
for(i=0;i<G.vexnum;i++) 
G.vexs[i].num=i; 
strcpy(G.vexs[0].name,"��԰ʳ��"); 
strcpy(G.vexs[0].introduction,"��԰ʳ��"); 
strcpy(G.vexs[1].name,"����¥"); 
strcpy(G.vexs[1].introduction,"����¥��¥��4��"); 
strcpy(G.vexs[2].name,"5��ѧ������¥"); 
strcpy(G.vexs[2].introduction,"�����ϵ��������¥����ʽ����"); 
strcpy(G.vexs[3].name,"ҽ����"); 
strcpy(G.vexs[3].introduction,"УҽԺ,��ʩһ��"); 
strcpy(G.vexs[4].name,"ͼ���"); 
strcpy(G.vexs[4].introduction,"��������,��ʩ���ã���������"); 
strcpy(G.vexs[5].name,"����"); 
strcpy(G.vexs[5].introduction,"�ִ����ܽ��ܵ�,�����ƺ,���˶�������ĳ���"); 
strcpy(G.vexs[6].name,"��԰"); 
strcpy(G.vexs[6].introduction,"��������,������Ϣ�Ͷ���"); 
strcpy(G.vexs[7].name,"����ѧ¥"); 
strcpy(G.vexs[7].introduction,"ѧԺ���Ľ�ѧ¥,��20�㣬���ν���,����ѧϰ"); 
strcpy(G.vexs[8].name,"��ѧ¥"); 
strcpy(G.vexs[8].introduction,"��ʩ����"); 
strcpy(G.vexs[9].name,"����¥"); 
strcpy(G.vexs[9].introduction,",�˶���ʩ�Ƚ�,��������"); 
for(i=0;i<G.vexnum;i++) 
for(j=0;j<G.vexnum;j++) 
G.arcs[i][j].adj=MINFINITY; 
G.arcs[0][1].adj=100; 
G.arcs[0][2].adj=200; 
G.arcs[0][6].adj=400; 
G.arcs[1][7].adj=300; 
G.arcs[2][3].adj=120; 
G.arcs[3][6].adj=220; 
G.arcs[3][4].adj=100; 
G.arcs[4][5].adj=300; 
G.arcs[4][9].adj=250; 
G.arcs[5][9].adj=350; 
G.arcs[6][7].adj=60; 
G.arcs[6][9].adj=200; 
G.arcs[7][8].adj=50; 
G.arcs[8][9].adj=20; 
for(i=0;i<G.vexnum;i++) 
for(j=0;j<G.vexnum;j++) 
G.arcs[j][i].adj=G.arcs[i][j].adj; 
return G; 
}//InitGraph end 
void Menu() 
{ 
printf("\n ������ѧ����ͼ\n"); 
printf(" ��������������������������������������������\n"); 
printf(" �� 1.���У԰ȫ�� ��\n"); 
printf(" �� 2.�鿴��������·�� ��\n"); 
printf(" �� 3.ѡ��������Ŀ�ĵ� ��\n"); 
printf(" �� 4.�鿴������Ϣ ��\n"); 
printf(" �� 5.�˳�ϵͳ ��\n"); 
printf(" ��������������������������������������������\n"); 
printf("Option-:"); 
} 
void Browser(MMGraph *G) 
{ 
int v; 
printf("�������ש����������������ש�����������������������������������������������������������\n"); 
printf("����ũ��������� ����� ��\n"); 
for(v=0;v<G->vexnum;v++) 
printf("��%-4d��%-16s��%-56s��\n",G->vexs[v].num,G->vexs[v].name,G->vexs[v].introduction); 
printf("�������ߩ����������������ߩ�����������������������������������������������������������\n"); 
} 

// �Ͻ�˹�����㷨���������㵽��������֮������·��,v0Ϊ��� 
void ShortestPath_DIJ(MMGraph * G) 
{ 
int v,w,i,min;
int t = 0;
int x1 = 0;
int v0;
int flag = 1;
int final[20], D[20], p[20][20]; 
while(flag) 
{ 
printf("������һ����ʼ������:"); 
scanf("%d",&v0); 
if(v0<0||v0>G->vexnum) 
{ 
printf("�����Ų�����!���������뾰����:"); 
scanf("%d",&v0); 
} 
if(v0>=0&&v0<G->vexnum) 
flag=0; 
} 
for(v=0;v<G->vexnum;v++) 
{ 
final[v]=0; 
D[v]=G->arcs[v0][v].adj; 

for(w=0;w<G->vexnum;w++) 
p[v][w]=0; 
if(D[v]<MINFINITY) 
{ 
p[v][v0]=1;p[v][v]=1; 
} 
} 
D[v0]=0;final[v0]=1; 
for(i=1;i<G->vexnum;i++) 
{ 
min=MINFINITY; 
for(w=0;w<G->vexnum;w++) 
if(!final[w]) 
if(D[w]<min){v=w;min=D[w];} 
final[v]=1; 
for(w=0;w<G->vexnum;w++) 
if(!final[w]&&(min+G->arcs[v][w].adj<D[w])) 
{ 
D[w]=min+G->arcs[v][w].adj; 
for(x1=0;x1<G->vexnum;x1++) 
p[w][x1]=p[v][x1]; 
p[w][w]=1; 
} 
} 
for(v=0;v<G->vexnum;v++) 
{ 
if(v0!=v) printf("%s",G->vexs[v0].name); 
for(w=0;w<G->vexnum;w++) 
{ 
if(p[v][w]&&w!=v0) printf("-->%s",G->vexs[w].name); 
t++; 
} 
if(t>G->vexnum-1&&v0!=v)printf(" ��·�߳�%dm\n\n",D[v]); 
} 

}//ShortestPath_DIJ end 
void Floyd(MMGraph *G) 
{ 
int v,u,i,w,k,j,flag=1,p[10][10][10],D[10][10]; 
for(v=0;v<G->vexnum;v++) 
for(w=0;w<G->vexnum;w++) 
{ 
D[v][w]=G->arcs[v][w].adj; 
for(u=0;u<G->vexnum;u++) 
p[v][w][u]=0; 
if(D[v][w]<MINFINITY) 
{ 
p[v][w][v]=1;p[v][w][w]=1; 
} 
} 
for(u=0;u<G->vexnum;u++) 
for(v=0;v<G->vexnum;v++) 
for(w=0;w<G->vexnum;w++) 
if(D[v][u]+D[u][w]<D[v][w]) 
{ 
D[v][w]=D[v][u]+D[u][w]; 
for(i=0;i<G->vexnum;i++) 
p[v][w][i]=p[v][u][i]||p[u][w][i]; 
} 

while(flag) 
{ 
printf("������������Ŀ�ĵصı��:"); 
scanf("%d%d",&k,&j); 
if(k<0||k>G->vexnum||j<0||j>G->vexnum) 
{ 
printf("�����Ų�����!����������������Ŀ�ĵصı��:"); 
scanf("%d%d",&k,&j); 
} 
if(k>=0&&k<G->vexnum&&j>=0&&j<G->vexnum) 
flag=0; 
} 
printf("%s",G->vexs[k].name); 
for(u=0;u<G->vexnum;u++) 
if(p[k][j][u]&&k!=u&&j!=u) 
printf("-->%s",G->vexs[u].name); 
printf("-->%s",G->vexs[j].name); 
printf(" ��·�߳�%dm\n",D[k][j]); 
}//Floyd end 
void Search(MMGraph *G) 
{ 
int k,flag=1; 
while(flag) 
{ 
printf("������Ҫ��ѯ�ľ�����:"); 
scanf("%d",&k); 
if(k<0||k>G->vexnum) 
{ 
printf("�����Ų�����!���������뾰����:"); 
scanf("%d",&k); 
} 
if(k>=0&&k<G->vexnum) 
flag=0; 
} 
printf("�������ש����������������ש���������������������������������������������������������\n"); 
printf("����ũ��������� ����� ��\n"); 
printf("��%-4d��%-16s��%-56s��\n",G->vexs[k].num,G->vexs[k].name,G->vexs[k].introduction); 
printf("�������ߩ����������������ߩ���������������������������������������������������������\n"); 

}//Search end 

int LocateVex(MMGraph *G,char* v) 
{ 
int c=-1,i; 
for(i=0;i<G->vexnum;i++) 
if(strcmp(v,G->vexs[i].name)==0) 
{c=i;break;} 
return c; 
} 
MMGraph * CreatUDN(MMGraph *G)//��ʼ��ͼ�Σ������û����� 
{ 
int i,j,k,w; 
char v1[20],v2[20]; 
printf("������ͼ�Ķ�����,����:"); 
scanf("%d%d",&G->vexnum,&G->arcnum); 
printf("�����뾰��ı��:�����ơ����:\n"); 
for(i=0;i<G->vexnum;i++) 
{ 
printf("������:"); 
scanf("%d",&G->vexs->num); 
printf("��������:"); 
scanf("%s",G->vexs[i].name); 
printf("������:"); 
scanf("%s",G->vexs->introduction); 
} 
for(i=0;i<G->vexnum;i++) 
for(j=0;j<G->vexnum;j++) 
G->arcs[i][j].adj=MINFINITY; 
printf("������·������:\n"); 
for(k=0;k<G->arcnum;k++) 
{ 
printf("��%d����:\n",k+1); 
printf("�����(x,y):"); 
scanf("%s",v1); 
scanf("%s",v2); 
printf("·������:"); 
scanf("%d",&w); 
i=LocateVex(G,v1); 
j=LocateVex(G,v2); 
if(i>=0&&j>=0) 
{ 
G->arcs[i][j].adj=w; 
G->arcs[j][i]=G->arcs[i][j]; 
} 
} 
return G; 
} 



void print(MMGraph *G) 
{ 
int v,w,t=0; 
for(v=0;v<G->vexnum;v++) 
for(w=0;w<G->vexnum;w++) 
{ if(G->arcs[v][w].adj==MINFINITY) 
printf("�� "); 
else printf("%-7d",G->arcs[v][w].adj); 
t++; 
if(t%G->vexnum==0) 
printf("\n"); 
} 
}