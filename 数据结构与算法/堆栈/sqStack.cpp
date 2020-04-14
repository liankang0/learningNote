#include "sqStack.h"

//初始化栈
Status initStack(SqStack &S, int size, int inc )
{
    S.elem = (ElemType *)malloc(size * sizeof(ElemType));
    if(NULL == S.elem)
        return OVERFLOW;
    S.top = 0;
    S.size = size;
    S.increment = inc;
    return OK;
}
//销毁栈
Status destoryStack(SqStack &S)
{
    free(S.elem);
    S.elem = NULL;
    return OK;
}
//判断栈是否为空
Status emptyStack(SqStack &S)
{
    if(0 == S.top)
        return TRUE;
    return FALSE;
}
//清空栈
Status clearStack(SqStack &S)
{
    if(0 != S.top)
    {
        S.size = 0;
        S.top = 0;
    } 
    return OK;
}
//将元素e压栈
Status pushStack(SqStack &S, ElemType e)
{
    ElemType * newBase;
    if(S.top >= S.size)
    {
        newBase = (ElemType *)realloc(S.elem, (S.size + S.increment));
        if(NULL == newBase) return OVERFLOW;
        S.elem = newBase;
        S.size += S.increment;
    }
    S.elem[S.top++] = e;
    return OK;
}
//取出栈顶元素，用e返回
Status getTopStack(SqStack &S, ElemType &e)
{
    if(0 == S.top) return OVERFLOW;
    e = S.elem[S.top - 1];
    return OK;
}
//出栈
Status popStack(SqStack &S, ElemType &e)
{
    if(0 == S.top) return OVERFLOW;
    e = S.elem[S.top - 1];
    S.top--;
    return OK;
}

