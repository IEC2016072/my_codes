#include<stdio.h>
int front=0,rear = -1;
void enqueue(int queue[],int x)
{
    if(rear==9&&front==0)
        printf("queue is overflow\n");
    else if(rear==front)
            printf("queue is overflow\n");
    else if(rear==9&&front>0)
            {
            rear=0;
            queue[rear]=x;
            rear++;
            }
    else
        {
        rear=rear+1;
        queue[rear]=x;
        }
}
void dequeue(int queue[])
{
    if(front==rear + 1)
        printf("queue is underflow\n");
    else {
    printf("%d\n",queue[front]);
    front++;
    }
}
int main()
{
    int n,i,x,type,queue[10];
    for(i=0;i<16;i++)
    {
        scanf("%d",&type);
    if(type==1)
    {
        scanf("%d",&x);
        enqueue(queue,x);
    }
    if(type==0)
    {
        dequeue(queue);

    }
    }
    return 0;
}
