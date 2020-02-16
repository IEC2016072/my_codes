#include<stdio.h>
struct node
{
    int data;
    struct node*next;
};
struct node*insertnode(struct node*start,int x)
{
    struct node*p = start;
    struct node*temp;
    temp = (struct node*)malloc(sizeof (struct node));
    if(start == NULL)
    {
        temp->data = x;
        start = temp;
        temp->next = start;
        return (start);
    }
    else
    {
        while(p->next!=start)
            p = p->next;
        temp->data = x;
        temp->next = start;
        p->next = temp;
        return (start);
    }
}
void display(struct node*start)
{
    struct node*p = start;
    printf("%d\n",p->data);
    p = p->next;
    while(p!=start)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}
struct node* delete(struct node*start,int y)
{

    struct node*p = start;
    struct node*q = p;
    while(q->next!=start)
        q = q->next;
    while(1)
    {
        if(start->data == y)
        {
            q->next = p->next;
            p = p->next;
            start = p;
        }
        else
            break;
    }
    q = p;
    p = p->next;
    while(p->next!=start)
    {
        if(p->data == y)
        {
            q->next = p->next;
            p = p->next;
        }
        else
        {
            q= q->next;
            p = p->next;
        }

    }
    if(p->data == y)
        q->next = p->next;
    return(start);
}
int main()
{
    int n,i,x,y;
    struct node*start;
    start = NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        start = insertnode(start,x);
    }
    display(start);
    printf("enter no you want to delete\n");
    scanf("%d",&y);
    start = delete(start,y);
    display (start);
    return 0;
}
