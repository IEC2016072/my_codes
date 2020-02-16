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
    struct node*w;
    struct node*y;

    int j,a=0,b=0;
    int min = abs(p->data - p->next->data);
    for(i=0;p!=NULL;i++)
    {
        q = p->next;
        for(j=0;q!=NULL;j++)
        {
            if(abs(q->data - p->data) <= min)
            {
                min = abs(q->data - p->data);
                a = q->data;
                b = p->data;
                w = p;
                y = q;
            }
            q = q->next;
        }
        p = p->next;
    }
    printf("%d %d\n\n",a,b);
    w->next = y;
    display(start);
    return 0;
}
