#include<stdio.h>
void push1(char expr[],char x,int*top1)
{
    *top1= *top1 + 1;
    expr[*top1]=x;
    printf("%s\n\n",expr);
}
void push2(char stack[],char x,int*top2)
{
    *top2 = *top2 + 1;
    stack[*top2]=x;
    printf("%s\n\n",stack);
}
char pop2(char stack[],int* top2)
{
    char p;
    p=stack[*top2];
    *top2 = *top2 - 1;
    return(p);
}
int main()
{
    char s[100],expr[100],stack[100],p;
    int i,top1 = -1,top2 = -1,l;
    scanf("%s",s);
    for(l=0;s[l]!='\0';l++);
    printf("%d\n\n",l);
    for(i=0;i<l;i++)
    {
        if(s[i]>=65&&s[i]<=90)
        {
            push1(expr,s[i],&top1);
        }
        if(s[i]=='+'||s[i]=='-')
        {
            while(top2>=0)
            {
                if(stack[top2]=='*'||stack[top2]=='/'||stack[top2]=='^')
                {
                    p= pop2(stack,&top2);
                    push1(expr,p,&top1);
                }
                else
                {
                    push2(stack,s[i],&top2);
                    break;
                }
            }
            if(top2 == -1)
                push2(stack,s[i],&top2);
        }
        if(s[i]=='*'||s[i]=='/')
        {
             while(top2>=0)
            {
                if(stack[top2]=='^')
                {
                    p= pop2(stack,&top2);
                    push1(expr,p,&top1);
                }
                else {push2(stack,s[i],&top2); break;}
            }
            if(top2 == -1)
                push2(stack,s[i],&top2);
        }
        if(s[i]=='^')
            push2(stack,s[i],&top2);

    }
    if(s[i]=='\0')
        {
            while(top2> -1)
            {
                 p= pop2(stack,&top2);
                 push1(expr,p,&top1);
            }
        }
    expr[l] = NULL;
    printf("%s",expr);
    return 0;
}
