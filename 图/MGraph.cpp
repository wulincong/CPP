#ifndef MGRAPH_C
#define MGRAPH_C

#include "MGraph.h"


Status CreateGraph_M(FILE *fp ,MGraph &G){
    printf("G.kind>>>");
    Scanf(fp,"%d",&(G.kind));
    switch(G.kind)
    {
	    case DG: return CreateDG(G);
	    case DN: return 0;
	    default:return ERROR;
    }
}

Status CreateDG(MGraph &G){\
    printf("DG");
    return 0;
}


#endif