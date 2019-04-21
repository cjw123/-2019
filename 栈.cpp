#include<stdlib.h>
#include<stdio.h>
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

Status StackEmpty(SqStack s)
{
    if(s.top==s.base) return true;
    else return false;
}
void ClearStack(SqStack &s)
{
    s.top=s.base;
}
void DestroyStack(SqStack *s)
{
    free(s->base);
    //free(s);
}

 SqStack s;
 SElemType e;
//十进制转换为8进制

void TenTransfromToEight()
{
    int N;
    InitStack(s);
    scanf("%d",&N);
    while(N)
    {
        push(s,N%8);
        N = N / 8;
    }
    while(!StackEmpty(s))
    {
        pop(s,e);
        printf("%d",e);
    }
}
//行编辑程序
void LineEdit()
{
    InitStack(s);
    int c;
    c = getchar();
    while(c!=EOF)
    {
        while(c!=EOF&&c!='\n')
        {
            switch (c)
            {
                case '#':
                    /* code */
                    pop(s,c);
                    break;
                case '@':
                    ClearStack(s);
                default:
                    push(s,c);break;
            }
            c = getchar();
        }
        ClearStack(s);
        if(c!=EOF) c = getchar();
    }
    DestroyStack(&s);
}
int main()
{
   LineEdit();
   return 0;

}