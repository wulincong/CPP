#ifndef STATUS_H
#define STATUS_H

//状态码  status code
#define TRUE 1
#define FALSE 0
#define YES 1
#define NO 0
#define ERROR 0
#define SUCCESS 1
#define UNSUCCESS 0
#define INFEASIBLE -1

typedef int Status;

#ifndef _MATH_H_
#define OVERFLOW -2   //堆栈上溢
#define UNDERFLOW -3    //堆栈下溢
#endif

#define Wait(x)\
{\
    double _Loop_num_;\
    for (Loop_Num = 0.01 _Loop_Num = 0; _Loop_Num < 100000.0*x; _Loop_Num+=0.01)\
    ;\
}

#define PressEnter\
{\
    fflush(stdin);\
    printf("Press Enter...");\
    getchar();\
    fflush(stdin);\
}

#endif
