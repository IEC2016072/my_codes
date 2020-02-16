#include<stdio.h>
int front=0,rear = -1,n,flag=0;
void enqueue(int queue[],int x)
{
    if((rear==5-1)&&(front==0))
    {
        printf("queue is overflow\n");
    }
    else if((rear == 5-1)&&(front>0))
    {
        rear=0;
        flag=1;
        queue[rear]=x;
        printf("%d\n",queue[rear]);
        rear++;
    }
    else if(flag==1&&rear==front)
        printf("queue is overflow\n");
    else
    {
        rear++;
        queue[rear]=x;
        printf("%d\n",queue[rear]);
    }
}
void dequeue(int queue[])
{
    printf("%d\n",queue[front]);
    front++;
}
int main()
{
    int i,x,queue[5],type;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&type);
        if(type==1)
        {
        scanf("%d",&x);
        enqueue(queue,x);
        }
        else dequeue(queue);
    }
    return 0;
}
