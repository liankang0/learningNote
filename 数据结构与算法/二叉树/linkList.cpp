#include "linkList.h"

//创建n个元素的链表L, 元素值存储在data数组中
Status createList(LinkList &L, ListDataType *data, int n)
{
    LNode *p, *q;
    int i;
    if(n < 0) return OVERFLOW;
    p = L = NULL;

    q = (LNode *)malloc(sizeof(LNode));
    if(NULL == q) return OVERFLOW;
    q->next = NULL;
    p = L = q;

    for(i = 0; i < n; i++)
    {
        q = (LNode *)malloc(sizeof(LNode));
        if(NULL == q) return OVERFLOW;
        q->data = data[i];
        p->next = q;
        q->next = NULL;
        p = q;
    }
    return OK;
}
//e从链表末尾入链表
Status enList(LinkList &L, ListDataType &e)
{
    LNode * p, * q;
    q = (LNode *)malloc(sizeof(LNode));
    if(NULL == q) return OVERFLOW;
    q->data = e;
    q->next = NULL;

    if(NULL == L)
    {   
        L = (LNode *)malloc(sizeof(LNode));
        if(NULL == L) return OVERFLOW;
        L->next = q;
    }
    else if(NULL == L->next)
    {
        L->next = q;
    }
    else
    {
        p = L;
        while(NULL != p->next)
        {
            p = p->next;
        }
        p->next = q;
    }
    
}
//e从链表头取出结点
Status deList(LinkList &L, ListDataType &e)
{
    if(NULL == L || NULL == L->next) return OVERFLOW;
    LNode * p;
    p = L->next;
    e = p->data;
    L->next = p->next;  
    free(p);
    return OK;
}
//遍历
Status travelList(LinkList &L)
{
    if(NULL == L || NULL == L->next) return OVERFLOW;
    for(LNode * p = L->next; NULL != p; p = p->next)
    {
        printf("%c ", p->data.data);
    }
    return OK;
}