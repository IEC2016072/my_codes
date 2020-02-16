#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*insertnode(struct node*start , int x)
{
    struct node*p = start;
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(start == NULL)
    {
        temp->data = x;
        temp->next = NULL;
        start = temp;
        return(start);
    }
    else
    {
        while(p->next!=NULL)
            p = p->next;
        temp->data = x;
        temp->next = NULL;
        p->next = temp;
        return(start);
    }
}
struct node*selectionsortll(struct node*start,int n)
{
    int i,j,min;
    struct node *p=start,*q,*r;
    for(i=0;i<n-1;i++)
    {
        p = start;
        for(j=0;j<i;j++)
            p = p->next;
        min = p->data;
        r = p;
        while(r!=NULL)
        {
            if(r->data<=min)
            {
                min = r->data;
                q = r;
            }
            r = r->next;
        }
        swap(&q->data,&p->data);
    }
    return(start);
}
void display(struct node*start)
{
    struct node*p = start;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
void swap(int*a,int*b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
    int n,i,x;
    struct node*start = NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        start = insertnode(start,x);
    }
    display(start);
    start = selectionsortll(start,n);
    display(start);
    return 0;
}
