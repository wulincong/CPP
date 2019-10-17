#ifndef MGRAPH_H
#define MGRAPH_H
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>


#include "Status.h"

//#include "Scanf.c"
//#include "LinkQueue.c"


#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

typedef enum GraphKind {DG = 1, DN, UDG, UDN} GraphKind;
typedef struct {} InfoType;
typedef int VRType;
typedef struct ArcCell{
	VRType adj;
	InfoType info;
} ArcCell;

typedef ArcCell AdjMatrix[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
typedef char VertexType_M;
typedef struct {
	VertexType_M vex[MAX_VERTEX_NUM+1];
	AdjMatrix arcs;
	int vexnum,arcnum;
	int IncInfo;
	enum GraphKind kind;
} MGraph;

//Status visited[MAX_VERTEX_NUM + 1];
//void (*VisitFunc)(VertexType_M e);

Status CreateGraph(MGraph &G);
Status CreateDG(MGraph &G);



#endif
