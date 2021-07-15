/*
迷宫相关操作列表
*/

#ifndef MAZE_H
#define MAZE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Status.h>

#define Question_8
#define N 15    //迷宫大小N*N
#define X 4     //用于随机数取余
#define SleepTime 15
#define SElemType_Sq block

typedef enum {
    Wall,               //外墙
    Obstacle,           //迷宫障碍
    Way,                //路径
    DeadLock,           //路径上的死胡同
    East,South,West,North //访问方向 东南西北
}MazeNode;

typedef struct {
    int x;              //块横坐标
    int y;              //块纵坐标
}PosType;

typedef struct {
    int order;          //通道块序号
    PosType seat;       //坐标
    int di;             //下一个访问的方向
}block;

#include "SequenceStack.h"
typedef int MazeType;

Status MazePath(MazeType maze[N][N], PosType start, PosType end);


void   InitMaze(MazeType maze[N][N], PosType *start, PosType *end);


void PaintMaze(MazeType maze[N][N]);
//画出迷宫

void ShowMaze(MazeType maze[N][N]);
//显示迷宫

Status EqualPosType(PosType a, PosType b);
//比较迷宫中两个通道块是否是同一个通道块

Status Pass(PosType seat, MazeType maze[N][N]);
//判定此通道是否未访问

Status FootPrint(PosType seat, MazeType maze[N][N]);
// 遇到未访问的节点时留下痕迹

void SetElemType(SElemType_Sq *e, int order, PosType seat, int di);
//更新通道块信息

PosType NextPos(PosType seat, int di);
//当前块的后继

Status IsCross(PosType seat);
//判断是否越界

void MarkPrint(PosType seat, MazeType maze[N][N]);
//标记当前位置上的通道块不可访问

#endif /* MAZE_H */