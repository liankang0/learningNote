#ifndef _SQ_STACK_
#define _SQ_STACK_

#include <stdio.h>
#include <stdlib.h>

//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef int ElemType;

typedef struct
{   
    ElemType * elem;
    int top;
    int size;
    int increment;
}SqStack;

//初始化栈
Status initStack(SqStack &s, int size, int inc );
//销毁栈
Status destoryStack(SqStack &s);
//判断栈是否为空
Status emptyStack(SqStack &s);
//清空栈
Status clearStack(SqStack &s);
//将元素e压栈
Status pushStack(SqStack &s, ElemType e);
//取出栈顶元素，用e返回
Status getTopStack(SqStack &s, ElemType &e);
//出栈
Status popStack(SqStack &s, ElemType &e);

#endif