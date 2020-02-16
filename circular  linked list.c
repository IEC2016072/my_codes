#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*next;
};
struct node* insertnode(struct node*start,int x)
{
    struct node*temp;
    struct node*p = start;
  //  p = (struct node*)malloc(sizeof(struct node));
    if(start == NULL)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data=x;
        start = temp;
        temp->next = start;
        return(start);
    }
    else
    {
        while(p->next != start)
        {
            p = p->next;
        }
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data=x;
        temp->next = start;
        p->next = temp;
        return(start);
    }
}
struct node* delete(struct node*start,int del)
{
    struct node*p;
    struct node*q;
    q = start;
    p = (struct node*)malloc(sizeof(struct node));
    struct node*tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    p = start;
    while(q->next!=start)
        q = q->next;
        while(p->next!=start)
        {
            while(start->data == del)
            {
                start = start->next;
                q->next = start;
                p = start;
            }
                if(p->data == del)
                {
                    q->next = p->next;
                    p = p->next;
                }
                else
                {
                    q = q->next;
                    p = p->next;
                }

        }
        if(p->data == del)
            q->next = start;
    return(start);
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
int main()
{
    int n,i,x,del;
    struct node*start;
    start = NULL;
    printf("No. of operations you want to perform\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Element you want to insert\n");
        scanf("%d",&x);
        start = insertnode(start,x);

    }
    printf("element you want to delete\n");
    scanf("%d",&del);
    start = delete(start,del);
    display(start);
}
