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
void display(struct node*start)
{
    struct node*p = start;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
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
    struct node*p = start;
    struct node*q = start;
    int n1,n2;
    printf("value of n1,n2 nodep,nodeq\n");
    scanf("%d%d",&n1,&n2);
    for(i=0;i<n1 -1;i++)
        p = p->next;
    for(i=0;i<n2-1;i++)
        q = q->next;
    if(q->next!=NULL)
    {
        struct node* a;
        struct node*b;
        struct node*c;
        struct node*d;
        a = p->next;
        b = p->next->next;
        c = q->next;
        d = q->next->next;
        if(q->next!=NULL)

        p->next = c;
        q->next->next = b;
        q->next = a;
        q->next->next = d;
    }
    display(start);
    return 0;
}
