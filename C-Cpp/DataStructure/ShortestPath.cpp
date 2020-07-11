#include<stdio.h>
  
#define SIZE 110  
#define INF 1000000;  
 
int map1[SIZE][SIZE];  //邻接矩阵存储 
int len[SIZE];  	//d[i]表示源点到i这个点的距离 
int visit1[SIZE];  //节点是否被访问 
int n,m;  
 
int dijkstra(int from, int to){	//从源点到目标点 
	
    int i;  
    
    for(i = 1 ; i <= n ; i ++){	//初始化 
        visit1[i] = 0;	//一开始每个点都没被访问 
        len[i] = map1[from][i];	//先假设源点到其他点的距离 
    }  
  
    int j;  
    for(i = 1 ; i < n ; ++i){	//对除源点的每一个点进行最短计算 
        int min = INF;  //记录最小len[i] 
        int pos;  //记录小len[i] 的点 
  
        for(j = 1 ; j <= n ; ++j){	
            if(!visit1[j] && min > len[j]){  
                pos = j;  
                min = len[j];  
            }  
        }  
        visit1[pos] = 1;  
  
        for(j = 1 ; j <= n ; ++j){
            if(!visit1[j] && (len[j] > (len[pos] +map1[pos][j]))){ //如果j节点没有被访问过&&j节点到源节点的最短路径>pos节点到源节点的最短路径+pos节点到j节点的路径  
                len[j] = len[pos] + map1[pos][j];	//更新j节点到源节点的最短路径	
            }  
        }  
    }  
  
    return len[to];
}
  
  
void shortestPath() {  
 
    int i,j;  
    
  //  scanf("%d%d",&n,&m);	//输入数据
	n = 6;	//测试数据 
	m = 9;
 
    for(i = 1 ; i <= n ; ++i){	//设一开始每个点都不可达 
        for(j = 1 ; j <= n ; ++j){  
            map1[i][j] = INF;  
        }  
    }  
	
/*	int a,b,c;	//输入数据 
    for(i = 1 ; i <= m ; ++i){  
        scanf("%d%d%d",&a,&b,&c);  
        map[a][b] = map[b][a] = c;  
    }  */
    
    map1[1][2] = 7;	//测试数据 
	map1[1][3] = 9;
	map1[1][6] = 14;
	map1[2][3] = 10;
	map1[2][4] = 15;
	map1[3][6] = 2;
	map1[5][6] = 9;
	map1[4][5] = 6;
	map1[3][4] = 11;
    int temp = INF;
	for(i = 1 ; i <= n ; ++i){
		for(j = 1 ; j <= n ; ++j){
			if(map1[i][j] == temp)
				map1[i][j] = map1[j][i];
		}
	}
 
    int ans = dijkstra(1,5);  
 
    printf("%d",ans);  
 
} 
 
/*	边的数据 
1 2 7
1 3 9
1 6 14
2 3 10
2 4 15
3 6 2
5 6 9
4 5 6
3 4 11
*/