#ifndef _TYPEDF_
#define _TYPEDF_

// typedef 作用域为单独文件，多文件时，要单独拿出来做头文件
typedef int Status;

typedef char BinTreeDataType;
//二叉树数据结构
typedef struct BTNode
{
    BinTreeDataType data;
    BTNode * lchild;
    BTNode * rchild;
}BTNode, *BinTree;

typedef BTNode StackDataType;
//栈数据结构
typedef struct
{   
    StackDataType * elem;
    int top;
    int size;
    int increment;
}SqStack;

typedef BTNode ListDataType;
//链表类型
typedef struct LNode
{
    ListDataType  data;
    struct LNode *next;
}LNode, *LinkList;

#endif