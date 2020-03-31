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
	int i,j,a,b;
	printf("请输入顶点数量>>>");
	scanf("%d",&G.vexnum);//获得顶点数量 
	printf("请输入边数量>>>");
	scanf("%d",&G.arcnum);
	printf("请输入顶点信息>>>");
	for(i = 0;i<G.vexnum;i++){
		printf("第%d个顶点>>>",i); 
		scanf("%d",&G.vex[i]);
	}
	for(i = 0;i<G.vexnum;i++){\
		for(j = 0;j<G.vexnum;j++){
			G.arcs[i][j] = 0;
		}
	}//for 初始化矩阵

	printf("下面输入边信息\n");
	for(i = 0;i<G.arcnum;i++){
		printf("边%d>>>",i);
		scanf("%d,%d",&a,&b);
		G.arcs[a][b] = 1;
	}
	return OK;
}


Status CreateUDN(MGraph &G){
	int i,j,k;
	scanf("%d,%d",&G.vexnum,&G.arcnum);
	for(i = 0;i<G.vexnum;i++)scanf("%d",&G.vex[i]);
	for(i = 0;i<G.vexnum;i++){
		for(j = 0;j<G.vexnum,j++) G.arcs[i][j] = {INFINITY,NULL};
	}
	for(k = 0;k<G.arcnum;k++){
		scanf("%d");
	}
}

#endif
