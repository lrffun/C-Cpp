#include<stdio.h>
  
#define SIZE 110  
#define INF 1000000;  
 
int map1[SIZE][SIZE];  //�ڽӾ���洢 
int len[SIZE];  	//d[i]��ʾԴ�㵽i�����ľ��� 
int visit1[SIZE];  //�ڵ��Ƿ񱻷��� 
int n,m;  
 
int dijkstra(int from, int to){	//��Դ�㵽Ŀ��� 
	
    int i;  
    
    for(i = 1 ; i <= n ; i ++){	//��ʼ�� 
        visit1[i] = 0;	//һ��ʼÿ���㶼û������ 
        len[i] = map1[from][i];	//�ȼ���Դ�㵽������ľ��� 
    }  
  
    int j;  
    for(i = 1 ; i < n ; ++i){	//�Գ�Դ���ÿһ���������̼��� 
        int min = INF;  //��¼��Сlen[i] 
        int pos;  //��¼Сlen[i] �ĵ� 
  
        for(j = 1 ; j <= n ; ++j){	
            if(!visit1[j] && min > len[j]){  
                pos = j;  
                min = len[j];  
            }  
        }  
        visit1[pos] = 1;  
  
        for(j = 1 ; j <= n ; ++j){
            if(!visit1[j] && (len[j] > (len[pos] +map1[pos][j]))){ //���j�ڵ�û�б����ʹ�&&j�ڵ㵽Դ�ڵ�����·��>pos�ڵ㵽Դ�ڵ�����·��+pos�ڵ㵽j�ڵ��·��  
                len[j] = len[pos] + map1[pos][j];	//����j�ڵ㵽Դ�ڵ�����·��	
            }  
        }  
    }  
  
    return len[to];
}
  
  
void shortestPath() {  
 
    int i,j;  
    
  //  scanf("%d%d",&n,&m);	//��������
	n = 6;	//�������� 
	m = 9;
 
    for(i = 1 ; i <= n ; ++i){	//��һ��ʼÿ���㶼���ɴ� 
        for(j = 1 ; j <= n ; ++j){  
            map1[i][j] = INF;  
        }  
    }  
	
/*	int a,b,c;	//�������� 
    for(i = 1 ; i <= m ; ++i){  
        scanf("%d%d%d",&a,&b,&c);  
        map[a][b] = map[b][a] = c;  
    }  */
    
    map1[1][2] = 7;	//�������� 
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
 
/*	�ߵ����� 
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