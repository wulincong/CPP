#include "Maze.h"

void visit(SElemType_Sq e){
    printf("x:%d, y:%d,", e.seat.x, e.seat.y);
    printf("di:%d\n", e.di);
}

Status MazePath(MazeType maze[N][N], PosType start, PosType end){
    SqStack S;
    SElemType_Sq nodeInf;   //存储当前通道块信息
    PosType curPos;         //当前位置
    int curStep;            //当前通道快序号

    InitStack_Sq(&S);
    curPos = start;
    curStep = 1;

    do{
        if(Pass(curPos, maze)){                             //当前位置可以通过
            FootPrint(curPos, maze);                        //留下足迹
            ShowMaze(maze);                                 
            SetElemType(&nodeInf, curStep, curPos, East);   //设置通道信息
            Push_Sq(&S, nodeInf);                           //加入路径
            if(EqualPosType(curPos, end)){                  //到达终点
                printf("\n Find path successful!");
                return OK;
            }
            curPos = NextPos(curPos, East);                 //下一个位置是当前位置的东邻
            curStep++;                           //探索下一步
        }
        else{
            if(!StackEmpty_Sq(S)){
                Pop_Sq(&S, &nodeInf);           //修改节点指向
                while(nodeInf.di == North && !StackEmpty_Sq(S)) //此通道块的四个方向都遍历了
                {
                    MarkPrint(nodeInf.seat, maze);
                    ShowMaze(maze);
                    // Wait(SleepTime);
                    Pop_Sq(&S, &nodeInf);
                    // StackTraverse_Sq(S, visit);
                }
                if(nodeInf.di < North){
                    nodeInf.di++;
                    maze[nodeInf.seat.x][nodeInf.seat.y] = nodeInf.di;  //改变方向
                    ShowMaze(maze);
                    Push_Sq(&S, nodeInf);
                    curPos = NextPos(nodeInf.seat, nodeInf.di);
                }
            } 
        }
    }while(!StackEmpty_Sq(S));

    printf("\nNone path!\n\n");
    return FALSE;
}


void   InitMaze(MazeType maze[N][N], PosType *start, PosType *end){
    int i, j,tmp;
    srand((unsigned)time(NULL));
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i == 0 || j == 0 || i == N-1 || j == N-1) maze[i][j] = Wall;
            else{
                tmp = rand() % X;           //生产随机数填充迷宫 0-3
                if(!tmp) maze[i][j] = Obstacle;
                else maze[i][j] = Way;
            }
        }
    }
    start->x = 1;
    start->y = 0;
    end->x = N-2;
    end->y = N-1;

    maze[1][0] = maze[N-2][N-1] = Way;
    maze[1][1] = maze[N-2][N-1] = Way;
}


void PaintMaze(MazeType maze[N][N]){
//画出迷宫
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(maze[i][j] == Wall    ) printf("@@");
            else if(maze[i][j] == Obstacle) printf("@@");
            else if(maze[i][j] == East    ) printf(">>");
            else if(maze[i][j] == South   ) printf("v ");
            else if(maze[i][j] == West    ) printf("<<");
            else if(maze[i][j] == North   ) printf("^ ");
            else if(maze[i][j] == DeadLock) printf("**");
            else printf("  ");
            if(j != 0 && j % (N-1) == 0) printf("\n");
        }
    }
}

void ShowMaze(MazeType maze[N][N]){
//显示迷宫
    Wait(SleepTime);
    system("cls");
    PaintMaze(maze);
}

Status EqualPosType(PosType a, PosType b){
//比较迷宫中两个通道块是否是同一个通道块
    if(a.x == b.x && a.y == b.y)
        return TRUE;
    else return FALSE;
}

Status Pass(PosType seat, MazeType maze[N][N]){
//判定此通道是否未访问
    int x = seat.x;
    int y = seat.y;
    if(!IsCross(seat) && maze[x][y] == Way)
        return TRUE;
    else
        return FALSE;
}

Status FootPrint(PosType seat, MazeType maze[N][N]){
// 遇到未访问的节点时留下痕迹
    maze[seat.x][seat.y] = East;        //留下痕迹即设置其下一次访问方向，向东
}

void SetElemType(SElemType_Sq *e, int order, PosType seat, int di){
//更新通道块信息
    e->order = order;
    e->seat = seat;
    e->di = di;
}

PosType NextPos(PosType seat, int di){
//当前块的后继
    PosType tmp = seat;
    switch (di){
        case East : tmp.y++; break;
        case South: tmp.x++; break;
        case West : tmp.y--; break;
        case North: tmp.x--; break;
    }
    return tmp;
}

Status IsCross(PosType seat){
//判断是否越界
    int x = seat.x;
    int y = seat.y;
    if(x<0 || y<0 || x>N-1 || y>N-1)
        return TRUE;
    else return FALSE;
}

void MarkPrint(PosType seat, MazeType maze[N][N]){
//标记当前位置上的通道块不可访问
    int x = seat.x;
    int y = seat.y;
    maze[x][y] = DeadLock;
}
