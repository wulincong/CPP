#ifndef SEQBINARYTREE_C
#define SEQBINARYTREE_C

#include "SeqBinaryTree.h"

void InitBiTree_Sq(SqBiTree T){
    // 1 构造二叉树
    int i;
    for(i=0;i<MAX_TREE_SIZE;i++) T[i]='\0';
}

void ClearBiTree_Sq(SqBiTree T){
    // 02 清空二叉树T
    int i;
    for(i=0;i<MAX_TREE_SIZE;i++) T[i]='\0';
}


void DestroyBiTree_Sq(SqBiTree T){   
    // 03 销毁二叉树
    // 无法销毁二叉树
}

Status BiTreeEmpty_Sq(SqBiTree T){
    // 04 判断二叉树是否为空
    return T[0]=='\0' ? TRUE : FALSE;
}


Status CreateBiTree_Le_Sq(FILE *fp, SqBiTree T){
    // 05 按层序序列构造二叉树
    char ch;
    int i = 0;
    while (Scanf(fp,"%c",&ch) == 1 && ch != '\n') {
        if (ch == '^') T[i++] = '\0';
        else T[i++] = ch;
    }
}


Status CreateBiTree_Pre_Sq(FILE *fp, SqBiTree T,int i);
// 06 按先序构造二叉树

int BiTreeLength_Sq(SqBiTree T);
// 07 返回二叉树长度

int BiTreeDepth_Sq(SqBiTree T);
// 08 返回二叉树深度

Status Root_Sq(SqBiTree T,TElemType_Sq *e);
// 09 用e返回二叉树的根

TElemType_Sq Value_Sq(SqBiTree T,Position s);
// 10 返回树中某个节点的值

Status Assign_Sq(SqBiTree T,Position s,TElemType_Sq value);
// 11 为树中的某个节点赋值

TElemType_Sq Parent_Sq(SqBiTree T,TElemType_Sq e);
// 12 返回某个节点的双亲节点值

TElemType_Sq LeftChild_Sq(SqBiTree T,TElemType_Sq e);
// 13 返回某节点的左孩子节点值

TElemType_Sq RightChild_Sq(SqBiTree T,TElemType_Sq e);
// 14 返回某结点的右孩子节点的值

TElemType_Sq LeftSibling_Sq(SqBiTree T,TElemType_Sq e);
// 15 左节点的值

TElemType_Sq RightSibling_Sq(SqBiTree T,TElemType_Sq e);
// 16 返回某节点的右兄弟节点值

void LevelOrderTraverse_Sq(SqBiTree T,void(* Visit)(TElemType_Sq));
// 17 层次遍历二叉树

void PreOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq),int i);
// 18 前序遍历二叉树

void InOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq),int i);
// 19 中序遍历二叉树

void PostOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq),int i);
// 20 后序遍历二叉树

void Print_Sq(SqBiTree T);
// 21 按二叉树的结构打印树

#endif