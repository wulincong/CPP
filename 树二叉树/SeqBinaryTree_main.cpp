#include "SeqBinaryTree.h"

void PrintElem(char c);
int main(int argc, char* argv[]){
    SqBiTree T;
    printf("函数InitBiTree_Sq测试\n");
    {
        printf("初始化空二叉树T...\n");
        InitBiTree_Sq(T);
        printf("\n");

    }

    {
        printf("BiTreeEmpty?\n");
        BiTreeEmpty_Sq(T)?printf(" T empty\n") : printf("T is not empty\n");
    } 

    {
        FILE *fp;
        printf("按层次序列创建二叉树T。。。\n");
        fp = fopen("TestData_Le.txt","r");
        CreateBiTree_Le_Sq(fp,T);
        fclose(fp);
        printf("\n");
    }

    {
        printf("test for function Print_Sq");
        Print_Sq(T);
        printf("\n");
    }

    return 0;
}