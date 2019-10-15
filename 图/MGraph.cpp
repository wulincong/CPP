#include <stdio.h>
#include <Scanf.c>
#include <stdarg.h>
#define INFINITY 1000
#define MAX_VERTEX_NUM 100
typedef int Status;
#define OJBK 1
#define OK 1
#define ERROR 0
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct ArcCell{
    int adj;
    int *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM] ;


typedef struct 
{
    int vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum,arcnum;
    GraphKind kind;
} MGraph;

Status CreateDG(MGraph &G);

Status CreateGraph(MGraph &G){
    printf("G.kind>>>");
    Scanf(fp,"%d",&(G.kind));
    switch (G.kind)
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
