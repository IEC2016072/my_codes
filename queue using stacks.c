#include<stdio.h>
void push(int stack[],int x,int *top)
{
    *top = *top + 1;
    stack[*top] = x;
}
int pop(int stack[],int* top)
{
    int a = stack[*top];
    *top = *top - 1;
    return a;
}
int main()
{
    int q,i,type,x,c=0,top1=-1,top2=-1,j,y,stack1[1000],stack2[1000];
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&type);
        if(type == 1)
        {
            c=0;
            for(j=0;j<=top2;j++)
            {
                y=pop(stack2,&top2);
                push(stack1,y,&top1);
            }
            scanf("%d",&x);
            push(stack1,x,&top1);
        }
        if(type==2)
        {
            c=1;
            for(j=0;j<=top1;j++)
            {
                y=pop(stack1,&top1);
                push(stack2,y,&top2);
            }
            y = pop(stack2,&top2);
        }
        printf("%d\n",top1);
        if(type==3)
        {
            if(c==0){
            for(j=0;j<=top1;j++)
            {
                y=pop(stack1,&top1);
                push(stack2,y,&top2);
            }
            printf("%d\n",stack2[top2]);}
            else printf("%d\n",stack1[top1]);
        }
    }
    return 0;
}
