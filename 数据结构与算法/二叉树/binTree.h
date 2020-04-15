#ifndef _BIN_TREE_H
#define _BIN_TREE_H



#include "linkList.h"
#include "sqStack.h"
#include "typedef.h"

//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

// //类型定义
// typedef int Status;

// typedef char BinTreeDataType;
// //二叉树数据结构
// typedef struct BTNode
// {
//     BinTreeDataType data;
//     BTNode * lchild;
//     BTNode * rchild;
// }BTNode, *BinTree;


//层次建树，使用链表辅助
BinTree createBinTree(BinTree B, BinTreeDataType * cArr, int size);
//递归遍历
Status preOrder(BinTree B);
Status inOrder(BinTree B);
Status postOrder(BinTree B);
//非递归遍历
Status preOrderNot(BinTree B);
Status inOrderNot(BinTree B);
Status postOrderNot(BinTree B);
//层次遍历
Status sequenceOreder(BinTree B);
#endif