#ifndef MGRAPH_H
#define MGRAPH_H
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>

#include "../����/Status.h"
//#include "Status.h"

//#include "Scanf.c"
//#include "LinkQueue.c"


#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

typedef enum GraphKind {DG = 1, DN, UDG, UDN} GraphKind;
typedef struct {} InfoType;
typedef int VRType;
typedef struct ArcCell{
	VRType adj;       // 0 1 ��ʾ���ޱ� 
	//InfoType info;        //�ߴ洢����Ϣ 
} ArcCell;

typedef ArcCell AdjMatrix[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
typedef int VertexType_M;
typedef struct {
	VertexType_M vex[MAX_VERTEX_NUM+1];  //������Ϣ 
	AdjMatrix arcs;           //����Ϣ 
	int vexnum,arcnum;        //���������������� 
//	int IncInfo;          
	enum GraphKind kind;      //ͼ���� 
} MGraph;


//Status visited[MAX_VERTEX_NUM + 1];
//void (*VisitFunc)(VertexType_M e);

Status CreateGraph(MGraph &G);
Status CreateDG(MGraph &G);
Status CreateDN(MGraph &G);
Status CreateUDG(MGraph &G);
Status CreateUDN(MGraph &G);

#endif

