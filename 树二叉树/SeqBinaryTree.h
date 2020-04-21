//
// Created by wulin on 2020/1/19 0019.
//
/*
 * 二叉树的顺序存储相关操作
 *
 *
 * */
#ifndef CPP_SEQBINARYTREE_H
#define CPP_SEQBINARYTREE_H
#include <cstdio>
#include <stdlib.h>
#include "Status.h"
#include <math.h>
#define MAX_TREE_SIZE 100

typedef int Status;
typedef char TElemType_Sq;
typedef TElemType_Sq SqBiTree[MAX_TREE_SIZE];

//节点 "坐标" 类型
typedef struct {
    int level;   //节点所在的层
    int order;   //节点在本层中的序号
}Position;

void InitBiTree_Sq(SqBiTree T);
// 1 构造二叉树

void ClearBiTree_Sq(SqBiTree T);
// 02 清空二叉树T

void DestroyBiTree_Sq(SqBiTree T);
// 03 销毁二叉树

Status BiTreeEmpty_Sq(SqBiTree T);
// 04 判断二叉树是否为空

Status CreateBiTree_Le_Sq(FILE *fp, SqBiTree T);
// 05 按层序序列构造二叉树

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

#endif //CPP_SEQBINARYTREE_H
