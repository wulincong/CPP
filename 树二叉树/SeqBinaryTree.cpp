#ifndef SEQBINARYTREE_C
#define SEQBINARYTREE_C

#include "SeqBinaryTree.h"

void 
InitBiTree_Sq(SqBiTree T){
    // 1 构造二叉树
    int i;
    for(i=0;i<MAX_TREE_SIZE;i++) T[i]='\0';
}

void 
ClearBiTree_Sq(SqBiTree T){
    // 02 清空二叉树T
    int i;
    for(i=0;i<MAX_TREE_SIZE;i++) T[i]='\0';
}


void 
DestroyBiTree_Sq(SqBiTree T){   
    // 03 销毁二叉树
    // 无法销毁二叉树
}

Status 
BiTreeEmpty_Sq(SqBiTree T){
    // 04 判断二叉树是否为空
    return T[0]=='\0' ? TRUE : FALSE;
}


Status 
CreateBiTree_Le_Sq(FILE *fp, SqBiTree T){
    // 05 按层序序列构造二叉树
    char ch;
    int i = 0;
    while (Scanf(fp,"%c",&ch) == 1 && ch != '\n') {
        if (ch == '^') T[i++] = '\0';
        else T[i++] = ch;
    }
}


Status 
CreateBiTree_Pre_Sq(FILE *fp, SqBiTree T,int i)
{
// 06 按先序构造二叉树
    char ch;
    Scanf(fp, "%c",&ch);
    if(ch == '^') T[i] = '\0';
    else{
        T[i] = ch;
        CreateBiTree_Pre_Sq(fp,T,2*i+1);
        CreateBiTree_Pre_Sq(fp,T,2*i+2);
    }
    return OK;
}

int 
BiTreeLength_Sq(SqBiTree T){
// 07 返回二叉树长度，从后向前找不是'\0'的位置
    int len;
    for(len = MAX_TREE_SIZE;len-1>0;len--){
        if(T[len-1] != '\0') break;
    }
    return len;
}


int 
BiTreeDepth_Sq(SqBiTree T){
// 08 返回二叉树深度
    int level = 0;
    int len = BiTreeLength_Sq(T);
    while((int)pow(2,level)-1 < len)level++;
    return level;
}

Status 
Root_Sq(SqBiTree T,TElemType_Sq *e){
// 09 用e返回二叉树的根
    if(BiTreeEmpty_Sq(T)) return ERROR;
    *e = T[0];
    return OK;
}

TElemType_Sq 
Value_Sq(SqBiTree T,Position s){
// 10 返回树中某个节点的值
    int i = pow(2,s.level - 1) + s.order -1 -1;
    return T[i];
}

Status 
Assign_Sq(SqBiTree T,Position s,TElemType_Sq value){
// 11 为树中的某个节点赋值
    int i = pow(2,s.level - 1) + s.order-2;
    if(value == '\0' && (T[2*i + 1]!='\0' || T[2*i+2] != '\0'))return ERROR;
    else if(value != '\0' && (T[i+1]/2-1) == '\0')return ERROR;
    else T[i] = value;
    return OK;
}

TElemType_Sq 
Parent_Sq(SqBiTree T,TElemType_Sq e){
// 12 返回某个值的双亲节点值
    int i;
    if(T[0] != '\0'){
        for(i = 0;i<MAX_TREE_SIZE;i++){
            if(T[i] == e) return T[(i+1) / 2 - 1];
        }
    }
    return '\0';
}

TElemType_Sq 
LeftChild_Sq(SqBiTree T,TElemType_Sq e){
// 13 返回某节点的左孩子节点值
    int i;
    if(T[0] == '\0')return ERROR;
    for(i = 0;i<MAX_TREE_SIZE;i++){
        if(T[i] == e) return T[(2*i + 1)];
    }
    return '\0';
}

TElemType_Sq 
RightChild_Sq(SqBiTree T,TElemType_Sq e){
    // 14 返回某结点的右孩子节点的值
    int i;
    if(T[0] == '\0')return ERROR;
    for(i = 0;i<MAX_TREE_SIZE;i++){
        if(T[i] == e) return T[(2*i + 2)];
    }
    return '\0';
}

TElemType_Sq 
LeftSibling_Sq(SqBiTree T,TElemType_Sq e){
// 15 左节点的值
    int i;
    if(T[0] == '\0')return ERROR;
    for(i = 0;i<MAX_TREE_SIZE;i++){
        if(i%2 == 0 && T[i] == e) return T[(i-1)];
    }
    return '\0';
}

TElemType_Sq 
RightSibling_Sq(SqBiTree T,TElemType_Sq e){
// 16 返回某节点的右兄弟节点值
    int i;
    if(T[0] == '\0')return ERROR;
    for(i = 0;i<MAX_TREE_SIZE;i++){
        if(i%2 != 0 && T[i] == e) return T[(i + 1)];
    }
    return '\0';
}

void 
LevelOrderTraverse_Sq(SqBiTree T,void(* Visit)(TElemType_Sq)){
// 17 层次遍历二叉树,顺序表本身就是层次顺序的
    int i;
    int len = BiTreeLength_Sq(T);
    for(i=0;i<len;i++){
        if(T[i] != '\0')
            Visit(T[i]);
    }
}

void 
PreOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq),int i){
// 18 前序遍历二叉树
    if(T[0] != '\0'){
        Visit(T[i]);
        PreOrderTraverse_Sq(T,Visit,2*i+1);//左孩子

        PreOrderTraverse_Sq(T,Visit,2*i+2);//右孩子
    }
}

void 
InOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq),int i){
// 19 中序遍历二叉树
    if(T[0] != '\0'){
        PreOrderTraverse_Sq(T,Visit,2*i+1);//左孩子
        Visit(T[i]);
        PreOrderTraverse_Sq(T,Visit,2*i+2);//右孩子
    }
}


void 
PostOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq),int i){
// 20 后序遍历二叉树
    if(T[0] != '\0'){
        PreOrderTraverse_Sq(T,Visit,2*i+1);//左孩子
        PreOrderTraverse_Sq(T,Visit,2*i+2);//右孩子
        Visit(T[i]);
    }
}


void 
Print_Sq(SqBiTree T){
// 21 按二叉树的结构打印树
    int i,j,level;
    char tmp[MAX_TREE_SIZE][MAX_TREE_SIZE] = {};
    level = BiTreeDepth_Sq(T);
    for(i=0;i<level;i++)
        for(j=1;j<(int)pow(2,i-1);j++)
            tmp[i-1][(int)pow(2,level-i)+(j-1)*(int)pow(2,level-i+1)-1] = T[(int)pow(2,i-1)-1+j-1];

    for(i=0;i<level;i++)
    {
        for(j = 0 ;j<2*(int)pow(2,level-1)-1 ;j++)
        {
            if(tmp[i][j] != '\0') 
                printf("%c",tmp[i][j]);
            else printf(" ");
        }
        printf("\n");
    }
}

#endif