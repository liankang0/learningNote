#ifndef _SQ_STACK_
#define _SQ_STACK_

#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//栈还有问题，如果栈初始化太小的话，栈中的数据莫名其妙变化。
// typedef int Status;
// //栈数据结构
// typedef BinTree StackDataType;
// typedef struct
// {   
//     StackDataType * elem;
//     int top;
//     int size;
//     int increment;
// }SqStack;

//初始化栈
Status initStack(SqStack &s, int size, int inc );
//销毁栈
Status destoryStack(SqStack &s);
//判断栈是否为空
Status emptyStack(SqStack &s);
//清空栈
Status clearStack(SqStack &s);
//将元素e压栈
Status pushStack(SqStack &s, StackDataType e);
//取出栈顶元素，用e返回
Status getTopStack(SqStack &s, StackDataType &e);
//出栈
Status popStack(SqStack &s, StackDataType &e);

#endif