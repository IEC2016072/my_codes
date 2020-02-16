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
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
struct node*partition(struct node*start,struct node*end)
{
    printf("ee\n");
    struct node*p,*q,*r,*s;
    q= start,p = start, r = start;
    q = end;
    while(p!=q)
    {
        if(p->data<=q->data)
        {
            swap(&p->data,&r->data);
            s = r;
            r = r->next;
        }
        p = p->next;
    }
    swap(&r->data,&q->data);
    if(r==start)
        {
            printf("%d\n",r->data);
            return(start);
        }
    printf("%d\n",s->data);
    return(s);
}
void quicksortll(struct node*start,struct node*end)
{
    printf("bb\n");
    struct node*p;
    if(start!=end&&start!=NULL&&end!=NULL)
    {
        printf("cc\n");
        p = partition(start,end);
        printf("dd\n");
        quicksortll(start,p);
        if(p!=start)
            quicksortll(p->next->next,end);
        else if(p==start)
            quicksortll(p->next,end);
    }
    return(0);
}

int main()
{
    int n,i,x;
    struct node*start = NULL,*end;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        start = insertnode(start,x);
    }
    end = start;
    while(end->next!=NULL)
        end = end->next;
    display(start);
    quicksortll(start,end);
    printf("aa\n");
    display(start);
}
