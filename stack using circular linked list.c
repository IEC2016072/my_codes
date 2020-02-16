#include<stdio.h>
struct node
{
    int data;
    struct node*next;
};
struct node*push(struct node*top,int x)
{
    struct node*temp;
    if(top == NULL)
    {
        top->data = x;
        top->next = top;
    }
    else
    {

    }
}
int main()
{
    int n,type,i,x,struct node*top,struct node*start;
    top = NULL;
    start = NULL;
    printf("no of operations you want to perform\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("type of operation: 1 for push, 2 for pop\n");
        scanf("%d",&type);
        if(type == 1)
        {
            printf("element you want to push\n");
            scanf("%d",&x);
            top = push(top,x);
        }
        else top = pop(top);
    }
}
