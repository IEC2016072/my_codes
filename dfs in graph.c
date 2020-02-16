#include<stdio.h>
int n,top = -1;
void creategraph(int a[100][100])
{
    int b,c;
    printf("enter no of nodes\n");
    scanf("%d",&n);
    while(1)
    {
        printf("enter origin and destination vertex(-1 -1to quit)\n");
        scanf("%d%d",&b,&c);
        if(b == -1 && c== -1)
            break;
        a[b][c] = 1;
    }
}
void push(int i,int stack[])
{
    top++;
    stack[top] = i;
}
int pop(int stack[])
{
    int i = stack[top];
    top--;
    return(i);
}
int isempty(int stack[])
{
    if(top == -1)
        return(1);
    else return(0);
}
void dft(int v,int state[],int stack[],int a[100][100],int distance[],int predecessor[])
{
    int i;
    push(v,stack);
    state[v] = 1;
    while(!isempty(stack))
    {
        v=pop(stack);
        printf("%d\n",v);
        state[v] = 2;
        for(i=n-1;i>=0;i--)
        {
            if(state[i] == 0 && a[v][i] == 1)
            {
                push(i,stack);
                state[i] = 1;
            }
        }
    }
}
void dfs(int state[],int stack[],int a[100][100],int distance[],int predecessor[])
{
    int v;
    printf("enter the starting node for df traversal\n");
    scanf("%d",&v);
    dft(v,state,stack,a,distance,predecessor);
}
int main()
{
     int a[100][100],i,j,n,state[100],stack[100], v,u,count=0,path[100],distance[100],predecessor[100];
    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
        a[i][j] = 0;
     creategraph(a);
    for(i=0;i<100;i++)
        state[i] = 0;
    dfs(state,stack,a,distance,predecessor);
    while(1)
    {
        count =  0;
        printf("enter destination vertex(-1 to quit)\n");
        scanf("%d",&v);
        printf("\n%d\n",n);
        if(v<-1 || v>n-1)
        {
            printf("destination vertex does not exist\n");
            continue;
        }
        if(v == -1)
            break;
        if(distance[v] == 9999)
        {
            printf("no path from starting vertex to destination vertex\n");
            continue;
        }
        else printf("shortest distance is : %d\n",distance[v]);
        while(v!=111)
        {
            count++;
            path[count] = v;
            u = predecessor[v];
            v = u;
        }
        printf("shortest path is : ");
        for(i=count;i>1;i--)
            printf("%d->",path[i]);
        printf("%d",path[i]);
        printf("\n");
    }
    return (0);
}
