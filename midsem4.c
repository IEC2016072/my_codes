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
struct node* hata(struct node*start,int max)
{
    struct node*p = start;
    struct node*q = p;
    while(p!=NULL&&p->next!=NULL)
    {
        if(start->data == max)
        {
            start = start->next;
            p = start;
        }
        else
        {
            q = p;
            p=p->next;
            if(p->data == max)
            {
                q->next = p->next;
            }
            else
            {
                q = q->next;
            }
        }
    }
return (start);
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
    int max=0;
    struct node*p = start;
    if(p!=NULL)
        max = p->data;
    printf("\n%d\n",max);
    while(p!=NULL)
    {
        if(p->data >= max)
            max = p->data;
        p = p->next;
    }
    printf("\n%d\n\n",max);
    start = hata(start,max);
    display(start);
}
