#include<stdio.h>
//size of array is 10//
int k;
int top[100];
void push(int stack[],int x,int sn)
{
    if(top[sn]==top[sn+1])
        printf("stack[%d] is overflow\n",sn);
    else if(top[sn]==11)
        printf("stack[%d] is overflow\n",sn);
    else
    {
    stack[top[sn]]=x;
    printf("%d\n",stack[top[sn]]);
    top[sn]++;
    }
}
int main()
{
    int n/*no of operations*/,i,x,type,sn,stack[10][100];
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        top[i+1]=(10/k)*i;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d %d",&x,&sn);
            push(stack[sn],x,sn);
        }
    }
}
