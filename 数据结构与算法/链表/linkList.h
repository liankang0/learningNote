#ifndef _LINK_LIST_
#define _LINK_LIST_

#include <stdio.h>
#include <stdlib.h>

//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//类型定义
typedef int Status;
typedef int ElemType;

//链表类型
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//创建n个元素的链表L, 元素值存储在data数组中
Status createList(LinkList &L, ElemType *data, int n);
//e从链表末尾入链表
Status enList(LinkList &L, ElemType &e);
//e从链表头取出结点
Status deList(LinkList &L, ElemType &e);
//遍历
Status travelList(LinkList &L);


#endif