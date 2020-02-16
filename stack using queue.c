#include<stdio.h>
void enqueue(int queue[],int x,int*rear)
{
    *rear = *rear + 1;
    queue[*rear] = x;
}
int dequeue(int queue[],int*front)
{
    int a;
    a = queue[*front];
    *front = *front + 1;
    return(a);
}
int main()
{
    int n,i,x,front1=0,front2=0,rear1= -1,rear2 = -1,queue1[100],queue2[100],j=1,p;
    printf("no of operations you want to perform\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(queue1,x,&rear1);
    }
    while(j<=n)
    {
        front1 = 0,front2 = 0,rear1= -1,rear2 = -1;
        if(j%2==1)
        {
            for(i=0;i<n-j;i++)
            {
                p = dequeue(queue1,&front1);
              //  printf("%d\n",p);
                enqueue(queue2,p,&rear2);
            }
            printf("%d\n",queue1[front1]);
            front1 = 0;
            rear2 = -1;
        }
        else
        {
             for(i=0;i<n-j;i++)
            {
                p = dequeue(queue2,&front2);
               // printf("%d\n",p);
                enqueue(queue1,p,&rear1);
            }
            printf("%d\n",queue2[front2]);
            rear1 = -1;
            front2 = 0;
        }
        j++;
    }
    return 0;
}
