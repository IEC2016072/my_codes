#include<stdio.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*insertnode(struct node*start,int x)
{
    struct node*temp;
    if(start==NULL)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=NULL;
        temp->prev=NULL;
        start= temp;
        return(start);
    }
    else
    {
        struct node*p=start;
        while(p->next!=NULL)
            p = p->next;
         temp = (struct node*)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=NULL;
        temp->prev=p;
        p->next = temp;
        return(start);
    }
}
struct node* hata(struct node*start,int del)
{
    struct node*p = start;
    while(p!=NULL)
    {
        if(start->data==del)
        {
            start= start->next;
            p = start;
            start->prev = NULL;
        }
        else
        {
            if(p->next!=NULL)
            {
                if(p->next->data == del)
                {
                    p->next = p->next->next;
                    if(p->next!=NULL)
                        p->next->prev = p;
                }
            }
            if(p!=NULL)
            p = p->next;
        }
    }
    return(start);
}
void display(struct node*start)
{
    struct node*p;
    p = (struct node*)malloc(sizeof (struct node));
    p = start;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}
int main()
{
    int n,i,x,del;
    struct node*start;
    start=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        start = insertnode(start,x);
    }
    display(start);
    scanf("%d",&del);
    start = hata(start,del);
    display(start);
    return 0;
}
