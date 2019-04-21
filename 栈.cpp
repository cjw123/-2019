#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef bool Status;
typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &s)
{
    s.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!s.base) return false;
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return true;
}

Status GetTop(SqStack s,SElemType &e)
{
    if(s.top == s.base) return false;
    e = *(s.top-1);
    return true;
}

Status push(SqStack &s,SElemType e)
{
    if(s.top-s.base>=s.stacksize)
    {
        s.base = (SElemType*)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
        s.top = s.base + s.stacksize;
        s.stacksize += STACKINCREMENT;
    }
    *s.top ++ = e;
    return true;
}

Status pop(SqStack &s,SElemType &e)
{
    if(s.top==s.base) return false;
    e = * --s.top;
    return true;
}