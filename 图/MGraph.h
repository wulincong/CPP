#ifndef MGRAPH_H
#define MGRAPH_H
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>

<<<<<<< HEAD
#include "../绪论/Status.h"
//#include "Status.h"
=======

#include "Status.h"
>>>>>>> c9a32f99b459e16e4ef198baa5406d2b08afad6e

//#include "Scanf.c"
//#include "LinkQueue.c"


#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

typedef enum GraphKind {DG = 1, DN, UDG, UDN} GraphKind;
typedef struct {} InfoType;
typedef int VRType;
typedef struct ArcCell{
	VRType adj;       // 0 1 表示有无边 
	//InfoType info;        //边存储的信息 
} ArcCell;

typedef ArcCell AdjMatrix[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
typedef int VertexType_M;
typedef struct {
<<<<<<< HEAD
	VertexType_M vex[MAX_VERTEX_NUM+1];  //顶点信息 
	AdjMatrix arcs;           //边信息 
	int vexnum,arcnum;        //顶点数量，边数量 
//	int IncInfo;          
	enum GraphKind kind;      //图类型 
=======
	VertexType_M vex[MAX_VERTEX_NUM+1];
	AdjMatrix arcs;
	int vexnum,arcnum;
	int IncInfo;
	enum GraphKind kind;
>>>>>>> c9a32f99b459e16e4ef198baa5406d2b08afad6e
} MGraph;


//Status visited[MAX_VERTEX_NUM + 1];
//void (*VisitFunc)(VertexType_M e);

Status CreateGraph(MGraph &G);
Status CreateDG(MGraph &G);
Status CreateDN(MGraph &G);
Status CreateUDG(MGraph &G);
Status CreateUDN(MGraph &G);

#endif

<<<<<<< HEAD
=======

#endif
>>>>>>> c9a32f99b459e16e4ef198baa5406d2b08afad6e
