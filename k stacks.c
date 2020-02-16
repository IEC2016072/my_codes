#include<stdio.h>
void push(int stack[],int x, int* top)
{
    *top = *top +1;
    stack[*top]=x;
}
void pop(int *top)
{
    *top = *top - 1;
}
int main()
{
    int  stack[100][100],top[100],n,i,x,data,sn,type;
    for(i=0;i<100;i++)
        top[i] = -1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d",&x,&sn);
            push(stack[sn],x,&top[sn]);
        }
        if(type==0)
        {
            scanf("%d",&sn);
            pop (top[sn]);
        }

    }
    return 0;
}
