#include<stdio.h>
void enqueue(int queue[],int x,int *rear)
{
    *rear = *rear + 1;
    queue[*rear]=x;
}
int dequeue(int queue[],int*front)
{
    int a;
    a= queue[*front];
    *front = *front + 1;
    return(a);
}
int main()
{
    int n,i,queue1[100],queue2[100],x,rear1= -1,rear2= -1,front1=0,count=0,front2=0,p;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(queue1,x,&rear1);
    }
     for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(queue2,x,&rear2);
    }
    while(front2<n)
    {
        if((queue1[front1] - queue2[front2]) == 0)
        {
            count++;
            front1++;
            front2++;
        }
        else
        {
            p = dequeue(queue1,&front1);
       //     printf("%d\n",p);
            enqueue(queue1,p,&rear1);
            count++;
        }

    }
    printf("%d",count);
    return 0;
}
