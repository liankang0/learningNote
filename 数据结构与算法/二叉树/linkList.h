#ifndef _LINK_LIST_
#define _LINK_LIST_

#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"




//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

// //类型定义
// typedef int Status;
// typedef BinTree ListDataType;

// //链表类型
// typedef struct LNode
// {
//     ListDataType data;
//     struct LNode *next;
// }LNode, *LinkList;

//创建n个元素的链表L, 元素值存储在data数组中
Status createList(LinkList &L, ListDataType *data, int n);
//e从链表末尾入链表
Status enList(LinkList &L, ListDataType &e);
//e从链表头取出结点
Status deList(LinkList &L, ListDataType &e);
//遍历
Status travelList(LinkList &L);


#endif