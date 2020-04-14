/*
    1.两种特殊的二叉树
        1）满二叉树
        2）完全二叉树
    2.二叉树定理
    3.二叉树遍历
        1）递归
        2）迭代

    满二叉树 --> 除叶子节点，其他节点都有两个非空子节点的二叉树
    完全二叉树 --> 除最后一层，其余层都是满的


    术语: 结点的度 --> 一个结点包含的子树个数
          树叶 --> 叶子节点，终端结点
          孩子结点 --> 相对于父节点（双亲结点）
          祖先结点 --> 从根结点到父节点都是
          子孙结点
          兄弟结点

          树的度 --> 使所有结点的度最大值（唯一性)

        >> 二叉树特点 --> 树的度 <= 2
                     --> 是有序树
    
    
    二叉树性质
    定理1 -->  若根结点的层数为1，在二叉树的i层至多有2（i-1)次方个结点
    定理2 -->  k层二叉树最多有2（k)次方 - 1个结点
    定理3 -->  n个结点的完全二叉树的层数为[log2N] + 1
    定理4 -->  二叉树度数为2节点的个数等于叶节点个数减1

*/
#include <iostream>

#include "stdio.h"
#include "stdlib.h"

//二叉树数据结构
struct biTreeElem
{
    char c;
    biTreeElem * lchild;
    biTreeElem * rchild;
};

//封装链表
struct listElem
{
    biTreeElem B;
    listElem * next;
    
};
//链表插入
listElem * insertList(listElem * head, char c)
{
    biTreeElem B;
    B.c = c;
    //如果头结点空
    if(head == NULL)
    {
        head = (listElem*)calloc(1, sizeof(listElem));
        head->B = B;
        head->next = NULL;
    }
    else  //如果头结点不空
    {
        listElem * currNode = head;
        listElem * newNode = (listElem*)calloc(1, sizeof(listElem));
        while(currNode->next != NULL)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;
        newNode->B = B;
        newNode->next = NULL;
    }
    return head;
}

//利用链表层次建树
biTreeElem  buildTree()
{
    listElem * phead = NULL;
    listElem * pTail;
    listElem * pCur;
    char c;
    while(scanf("%c", &c) != EOF)
    {
        if(c == '\n')
            break;
        if(phead == NULL)
        {
            phead = insertList(phead, c);
            pCur = phead;
            pTail = phead;
        }
        else
        {
            phead = insertList(phead, c);
            pTail = pTail->next;
            if(pCur->B.lchild == NULL)
            {
                pCur->B.lchild = &(pTail->B);
            }
            else
            {
                pCur->B.rchild = &(pTail->B);
                pCur = pCur->next;
            }
        }
    }
    return phead->B;
}

//遍历
//递归版
void preOrder(biTreeElem * p)
{
    if(p != NULL)
    {
        printf("%c ", p->c);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
void inOrder(biTreeElem * p)
{
    if(p != NULL)
    {
       
        inOrder(p->lchild); 
        printf("%c ", p->c);
        inOrder(p->rchild);
    }
}
void postOrder(biTreeElem * p)
{
    if(p != NULL)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%c ", p->c);
    }
}

//实现栈
typedef struct node
{
    biTreeElem B;
    node * next;
}Stack;
//初始化
Stack * createStack()
{
    Stack * stack = (Stack*)calloc(1, sizeof(Stack));
    if(stack != NULL)
    {
        stack->next = NULL;
        return stack;
    }
    printf("stack is error!");
    return NULL;
}
//入栈
void pushStack(Stack * stack, biTreeElem B)
{
    Stack * newStack = (Stack*)calloc(1, sizeof(Stack));
    newStack->B = B;
    newStack->next = stack->next;
    stack->next = newStack;
}
//出栈
void popStack(Stack * stack)
{
    if(stack->next != NULL)
    {
        stack->next = stack->next->next;
    }
}
//得到栈顶元素
Stack * topStack(Stack * stack)
{
    if(stack->next != NULL)
    {
        return stack->next;
    }
    return NULL;
}
//栈是否为空
bool isEmpty(Stack* stack)
{
    if(stack->next == NULL)
        return 1;
    return 0;
}
//迭代版  任何递归版本都可以转化为迭代版本，递归调用本质是压栈，以空间换时间
void preOrder1(biTreeElem * p)
{
    biTreeElem * root = p;
    biTreeElem * currBi;
    Stack* stack = createStack();
    if(root == NULL)
    {
        return;
    }
    else
    {
        pushStack(stack, *root);
        printf("%c ", root->c);
        topStack(stack)->B.lchild = NULL;
    }
    
    while(!isEmpty(stack))
    {
        if(root->lchild != NULL)
        {
            pushStack(stack, *(root->lchild));
            printf("%c ", root->lchild->c);
            root = root->lchild;
            topStack(stack)->B.lchild = NULL;

        }
        else if(root->rchild != NULL)
        {
            printf("%c ", root->rchild->c);
            topStack(stack)->B.rchild = NULL;
        }
        else
        {
            popStack(stack);
            root = &(topStack(stack)->B);
        }
        
    }



}

void inOrder1(biTreeElem * p)
{
    biTreeElem * root = p;
    biTreeElem * currBi;
    Stack* stack = createStack();
    while(root || !isEmpty(stack))
    {
        if(root)
        {
            pushStack(stack, *root);
            root = root->lchild;
        }
        else
        {
            root = &(topStack(stack)->B);
            putchar(root->c);
            root = root->rchild;
        }
        
    }
}

void postOrder1(biTreeElem * p)
{

}

int main()
{   
    biTreeElem  root = buildTree();
    printf("递归中序遍历——————————————————————————————————\n");
    // inOrder(&root);
    // printf("非递归中序遍历——————————————————————————————————\n");
  //  inOrder1(&root);
    
    
    return 0;
}


