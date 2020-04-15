#include "linkList.h"
#include "sqStack.h"
#include "binTree.h"



//层次建树，使用链表辅助
BinTree createBinTree(BinTree  B, BinTreeDataType * cArr, int size)
{
    if(0 >= size) return ERROR;
    int i;
    BinTree bArr = (BinTree)malloc(size * sizeof(BTNode));
    for(i = 0; i < size; i++)
    {
        bArr[i].data = cArr[i];
        bArr[i].lchild = NULL;
        bArr[i].rchild = NULL; 
    }
    LinkList L; //带头结点的链表
    createList(L, bArr, size);
    
    LNode * pFront, * pRear;
    pFront = L->next;
    pRear = L->next;
    B = NULL;
    while(NULL != pRear)
    {
        if(NULL == B)
        {
            B = &(pRear->data);
            pRear = pRear->next;
        }
        else if(NULL == (pFront->data).lchild)
        {
            (pFront->data).lchild = &(pRear->data);
            pRear = pRear->next; 
        }
        else if(NULL == (pFront->data).rchild)
        {
            (pFront->data).rchild = &(pRear->data);
            pRear = pRear->next;
        }
        else
        {
            pFront = pFront->next;
        }  
    }
    return B;
}
//递归遍历
Status preOrder(BinTree B)
{

    if(NULL == B) return ERROR;
    printf("%c ", B->data);
    preOrder(B->lchild);
    preOrder(B->rchild);
}
Status inOrder(BinTree B)
{

    if(NULL == B) return ERROR;
    inOrder(B->lchild);
    printf("%c ", B->data);
    inOrder(B->rchild);
}
Status postOrder(BinTree B)
{
    if(NULL == B) return ERROR;
    postOrder(B->lchild);
    postOrder(B->rchild);
    printf("%c ", B->data);
    
}
//非递归遍历 
//在入栈前打印
Status preOrderNot(BinTree B)
{
    BinTree root = B;
    BTNode temp;
    if(NULL == B) return ERROR;
    SqStack S;
    initStack(S, 1, 3);
    while(root || !emptyStack(S))
    {
        if(root)
        {
            printf("%c ", root->data);
            pushStack(S, *root);
            root = root->lchild;
            
        }
        else
        {
            popStack(S, temp);
            root = temp.rchild;
        }
    }
    return OK;
}
//在出栈后打印
Status inOrderNot(BinTree B)
{
    BinTree root = B;
    BTNode temp;
    if(NULL == B) return ERROR;
    SqStack S;
    initStack(S, 1, 3);
    while(root || !emptyStack(S))
    {
        if(root)
        {
            pushStack(S, *root);
            root = root->lchild;
            
        }
        else
        {
            popStack(S, temp);
            printf("%c ", temp.data);
            root = temp.rchild;
        }
    }
    return OK;
}
//使用两个栈实现
Status postOrderNot(BinTree B)
{
    BinTree root = B;
    BTNode temp, temp1;
    if(NULL == B) return ERROR;
    SqStack S, S1;
    initStack(S, 5, 5);
    initStack(S1, 5, 5);
    while(root || !emptyStack(S))
    {
        if(root)
        {
            pushStack(S, *root);
            root = root->lchild;
            
        }
        else
        {
            getTopStack(S, temp);
            getTopStack(S1, temp1);
            if(!emptyStack(S) && !emptyStack(S1) && temp1.data == temp.data)
            {
                popStack(S, temp);
                popStack(S1, temp1);
                printf("%c ", temp.data);
            }
            else
            {
                popStack(S, temp);
                if(NULL != temp.rchild) 
                {
                    pushStack(S, temp);
                    pushStack(S1, temp);
                }   
                else
                {
                    printf("%c ", temp.data);
                }
                root  = temp.rchild;
            }
        }
    }
    return OK;
}
//层次遍历
Status sequenceOreder(BinTree B)
{
    LinkList L;
    if(NULL == B) return OVERFLOW;
    enList(L, *B);
    LNode * pFront = L->next;
    BTNode * root = B;

    while(pFront)
    {
        if(pFront->data.lchild)
            enList(L, *(pFront->data.lchild));
        if(pFront->data.rchild)
            enList(L, *(pFront->data.rchild));
        pFront = pFront->next;
    }

    travelList(L);
    return OK;
}

