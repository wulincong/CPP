#ifndef MGRAPH_C
#define MGRAPH_C

#include "MGraph.h"
#define OK 1

Status CreateGraph(MGraph &G){
    printf("G.kind>>>"); 
    scanf("%d",&(G.kind));
    //printf("kind OK\n");
    switch(G.kind)
    {
	    case DG: return CreateDG(G);
	    case DN: return 0;
		case UDG: return CreateUDG(G);
	    default:return ERROR;
    }
    return 1;
}

Status CreateDG(MGraph &G){\
    printf("DG");
    return OK;
}

Status CreateUDG(MGraph &G){
	int i,a,b;
	printf("�����붥������>>>");
	scanf("%d",&G.vexnum);//��ö������� 
	printf("�����������>>>");
	scanf("%d",&G.arcnum);
	printf("�����붥����Ϣ>>>");
	for(i = 0;i<G.vexnum;i++){
		printf("��%d������>>>",i); 
		scanf("%d",&G.vexs[i]);
	}
	for(i = 0;i<G.vecnum;i++){\
		for(j = 0;j<G.vexnum;j++){
			G.arcs[i][j] = 0;
		}
	}//for ��ʼ������

	printf("�����������Ϣ\n");
	for(i = 0;i<G.arcnum;i++){
		printf("��%d>>>",i);
		scanf("%d,%d",&a,&b);
		G.arcs[a][b] = 1;
	}
	return OK;
}

Status CreateUDN(MGraph &G){
	int i,j,k;
	scanf("%d,%d",&G.vexnum,&G.arcnum);
	for(i = 0;i<G.vexnum;i++)scanf("%d",&G.vexs[i]);
	for(i = 0;i<G.vexnum;i++){
		for(j = 0;j<G.vexnum,j++) G.arcs[i][j] = {INFINITY,NULL};
	}
	for(k = 0;k<G.arcnum;k++){
		scanf()
	}
	
}
#endif
