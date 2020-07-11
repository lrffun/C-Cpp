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
	printf("\t\t\t\t                 ��ӭ�������ݽṹѧϰƽ̨                  \n\n");
	printf("\t\t\t\t                   ��ѡ����Ҫѧϰ������                  \n\n");
	printf("\t\t\t\t                    1. ͼ�Ļ�������\n\n");
	printf("\t\t\t\t                    2. ͼ�Ĵ洢\n\n");
	printf("\t\t\t\t                    3. ͼ�ı���\n\n");
	printf("\t\t\t\t                    4. ��С������\n\n");
	printf("\t\t\t\t                    5. ��������͹ؼ�·��\n\n");
	printf("\t\t\t\t                    6. ���·��\n\n");
	printf("\t\t\t\t                    7. ͼ���㷨Ӧ�þ���\n\n");
	printf("\t\t\t\t                    0. �˳�ϵͳ\n\n");
	printf("\t\t\t\t***********************************************************\n");

}

void con1(){
	int input = -1;
	system("cls");
	printf("\n\n\n\n\t\t\t\t***********************************************************\n");
	printf("\t\t\t\t                     ͼ�Ļ�������\n\n");
	printf("\t\t\t\t                    0. ����\n");
	printf("\t\t\t\t                    1. ͼ�Ķ���\n");
	printf("\t\t\t\t                    2. ����ͼ\n");
	printf("\t\t\t\t                    3. ����ͼ\n");
	printf("\t\t\t\t                    4. ��ͼ\n");
	printf("\t\t\t\t                    5. ��ȫͼ\n");
	printf("\t\t\t\t                    6. ��ͼ\n");
	printf("\t\t\t\t                    7. ��ͨ����ͨͼ����ͨ����\n");
	printf("\t\t\t\t                    8. ǿ��ͨͼ��ǿ��ͨ����\n");
	printf("\t\t\t\t                    9. ������������ɭ��\n");
	printf("\t\t\t\t                    10. ����Ķȡ���Ⱥͳ���\n");
	printf("\t\t\t\t                    11. �ߵ�Ȩ����\n");
	printf("\t\t\t\t                    12. ·����·�����Ⱥͻ�·\n");
	printf("\t\t\t\t                    13. ��·�����򵥻�·\n");
	printf("\t\t\t\t                    14. ����\n");
	printf("\t\t\t\t                    15. ������\n");
	printf("\n\n\n\n\t\t\t\t***********************************************************\n");
	scanf("%d",&input);
	switch(input){					//ѡ����
		case 0:break;
		case 1:system("cls");printf("\n\nͼ�Ķ��壺\nͼG�ɶ��㼯V�ͱ߼�E��ɣ���ΪG=(V,E)������V(G)��ʾͼG�ж�������޷ǿռ���E(G)��ʾͼG�ж���֮��Ĺ�ϵ(��)�ļ��ϡ�\n");break;
		case 2:system("cls");printf("\n\n����ͼ��\n��E������ߣ���ƻ��������޼���ʱ����GΪ����ͼ�����Ƕ��������ԣ���Ϊ<v,w>������ v��w �Ƕ��㣬v �ǻ�β��w �ǻ�ͷ����Ϊ�Ӷ���v������w�Ļ���\n");break;
		case 3:system("cls");printf("\n\n����ͼ��\n��E������ߣ���Ʊߣ������޼���ʱ����GΪ����ͼ�����Ƕ��������ԣ���Ϊ (v,w) ��(w,v) ������ (v,w) =(w,v) ������ v��w �Ƕ��㡣\n");break;
		case 4:system("cls");printf("\n\n��ͼ:\n��ͼ���������������ݣ�\n1���������ظ���\n2�������ڶ��㵽����ı�\n");break;
		case 5:system("cls");printf("\n\n��ȫͼ:\n����ͼ����������֮�䶼���ڱߣ���Ϊ������ȫͼ��������ͼ�е�ʾ��������ȫͼ��\n����ͼ����������֮�䶼���ڷ����򷴵�����������Ϊ������ȫͼ��\n");break;
		case 6:system("cls");printf("\n\n��ͼ��\n��������ͼG=(V,E),G1=(V1,E2)����V1��V���Ӽ���E2��E���Ӽ�����G1��G����ͼ��\n");break;
		case 7:system("cls");printf("\n\n��ͨ����ͨͼ����ͨ������\n������ͼ�У���������·�����ڣ��ͳ�Ϊ��ͨ�ġ���ͼ�����������㶼��ͨ��ͬ��ͼΪ��ͨͼ������ͼ�еļ�����ͨ��ͼ��Ϊ��ͨ������\n");break;
		case 8:system("cls");printf("\n\nǿ��ͨͼ��ǿ��ͨ������\n������ͼ�У�����������������·�����������Ϊǿ��ͨ������һ���㶼��ǿ��ͨ�ģ���Ϊǿ��ͨ������ͼ�м���ǿ��ͨ��ͼΪ����ͼ��ǿ��ͨ������\n");break;
		case 9:system("cls");printf("\n\n������������ɭ�֣�\n��ͨͼ���������ǰ���ͼ��ȫ�������һ����С��ͨ��ͼ����ͼ����n�����㣬����������n-1���ߡ����Զ������������ԣ�����ȥһ���ߣ��ͻ��ɷ���ͨͼ��\n");break;
		case 10:system("cls");printf("\n\n����Ķȡ���Ⱥͳ��ȣ�\n����Ķ�Ϊ�Ըö���Ϊһ���˵�ıߵ���Ŀ��\n��������ͼ������ı���Ϊ�ȣ�����֮���Ƕ��������������\n��������ͼ��������Զ���Ϊ�յ㣬�����෴������ͼ��ȫ���������֮�͵��ڳ���֮���ҵ��ڱ���������Ķȵ�����������֮�͡�\nע�⣺�����������������ͼ��˵�ġ�\n");break;
		case 11:system("cls");printf("\n\n�ߵ�Ȩ������\nͼ��ÿ�����ϱ���ĳ�ֺ������ֵ������ֵ��Ϊ�ñߵ�Ȩֵ������ͼ��Ϊ����ͼ��Ҳ��������\n");break;
		case 12:system("cls");printf("\n\n·����·�����Ⱥͻ�·��\n������֮���·��ָ����֮�侭���Ķ������У�����·���ϱߵ���Ŀ��Ϊ·�����ȡ�����n�����㣬�ұ�������n-1����ͼһ���л���\n");break;
		case 13:system("cls");printf("\n\n��·�����򵥻�·��\n���㲻�ظ����ֵ�·����Ϊ��·����\n����һ����������һ�������⣬���ඥ�㲻�ظ����ֵĻ�·��Ϊ�򵥻�·��\n");break;
		case 14:system("cls");printf("\n\n���룺\n�����������·�����������·������Ϊ���롣\n");break;
		case 15:system("cls");printf("\n\n��������\n��һ����������Ϊ0�����ඥ�����Ⱦ�Ϊ1������ͼ������������\n");break;
		default:break;
	}
	system("pause");
	if(input){con1();}
}

void con2(){
	system("cls");
	int input = -1;
	printf("\n\n\n\n\t\t\t\t***********************************************************\n\n");
	printf("\t\t\t\t		    ��ӭ����ͼ�Ĵ洢�½�                \n\n");
	printf("\t\t\t\t                   ��ѡ����Ҫ���ԵĴ洢����                  \n\n");
	printf("\t\t\t\t                    1. �����ʾ\n\n");
	printf("\t\t\t\t                    2. �ڽӱ�\n\n");
	printf("\t\t\t\t                    3. ʮ������\n\n");
	printf("\t\t\t\t                    4. �ڽӶ��ر�\n\n");
	printf("\t\t\t\t                    0. ������һ��\n\n");
	printf("\t\t\t\t***********************************************************\n");
	scanf("%d",&input);
	switch(input){					//ѡ����
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
	printf("ͼ�Ľṹ���£�\n");
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
	printf("\t\t\t\t			��ӭ������С�������½�                \n\n");
	printf("\t\t\t\t                   ��ѡ����Ҫ���Ե�����С����������                  \n\n\n");
	printf("\t\t\t\t                    0. ����\n\n");
	printf("\t\t\t\t                    1. Prim�㷨\n\n");
	printf("\t\t\t\t                    2. Kruskal�㷨\n\n");
	printf("\t\t\t\t***********************************************************\n");
	scanf("%d",&input);
	switch(input){					//ѡ����
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
	printf("��������룬������·����");
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
		switch(input){					//ѡ����
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