#include<stdio.h>
int front=0,rear= -1;
void enqueue(int queue[],int x,int side)
{
    if(side==1)
    {
        rear = rear + 1;
        queue[rear]=x;
    }
    if(side==0)
    {
        if(front==0)
            printf("not possible\n");
        else
        {
            front--;
            queue[front]=x;
        }
    }
}
void dequeue(int queue[],int side)
{
    if(side==1)
    {
        printf("%d\n",queue[rear]);
        rear--;
    }
    if(side==0)
    {
        printf("%d\n",queue[front]);
        front++;
    }

}
int main()
{
    int n,i,x,type,side;
    // type=0 -> dequeue,type=1 -> enqueue,side=0 -> left, side=1 -> right
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d",&x);
            scanf("%d",&side);
            enqueue(queue,x,side);
        }
        if(type==0)
        {
            scanf("%d",&side);
            dequeue(queue,side);
        }
    }
    return 0;
}
