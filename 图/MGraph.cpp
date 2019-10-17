#ifndef MGRAPH_C
#define MGRAPH_C

#include "MGraph.h"


Status CreateGraph(MGraph &G){
    printf("G.kind>>>"); 
    scanf("%d",&(G.kind));
    //printf("kind OK\n");
    switch(G.kind)
    {
	    case DG: return CreateDG(G);
	    case DN: return 0;
	    default:return ERROR;
    }
    return 1;
}

Status CreateDG(MGraph &G){\
    printf("DG");
    return 0;
}


#endif
