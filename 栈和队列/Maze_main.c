#include "Maze.h"

int main(int argc, char **argv){
    MazeType maze[N][N];
    PosType start, end;
    SElemType_Sq e;
    char Re = 'Y';
    while(Re == 'Y' || Re == 'y' || Re == '\n'){
        InitMaze(maze, &start, &end); //初始化迷宫
        ShowMaze(maze);
        MazePath(maze,start,end);

        printf("recover? \"Y/N\"");
        scanf("%c", &Re);
    }
} 