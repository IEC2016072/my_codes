//creating a doubly circular linked list
#include<stdio.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*insertnode(struct node*start,int x)
{
    struct node*p;
    struct node*temp;
    temp = (struct node*)malloc(sizeof (struct node));
    if(start == NULL)
    {
        temp->data = x;
        start = temp;
        temp->next = start;
        temp->prev = start;
        return(start);
    }
    else
    {
        p=start;
        while(p->next!=start)
            p=p->next;
        temp->data = x;
        temp->next = start;
        p->next = temp;
        temp->prev = p;
        start->prev=temp;
        return(start);
    }
}
struct node*hata(struct node*start,int del)
{
    int flag = 0;
    struct node*p;
   // p = (struct node*)malloc(sizeof (struct node));
   // struct node*temp1;
   // temp1 = (struct node*)malloc(sizeof (struct node));
   // struct node*temp2;
   // temp2 = (struct node*)malloc(sizeof (struct node));
    p = start;
    if(p->next == start)
    {
        printf("linked list has become null\n");
        return(start);
    }
    else if(p->data == del)
    {
      //  printf("fadfda\n");
        p->next->prev = p->prev;
        p->prev->next = p->next;
        start = p->next;
        return(start);
    }
    else
    {
        while(p->data!=del)
        {
            p=p->next;
            if(p == start)
            {
                flag == 1;
                printf("not found\n");
                return(start);
            }
        }
        if(flag==0)
        {
            p->prev->next = p->next;
            p->next->prev= p->prev;
            return(start);
        }
    }
}
void display1(struct node*start)
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
void display2(struct node*start)
{
    struct node*p = start;
    printf("%d\n",p->data);
    p = start->prev;
    while(p!=start)
    {
        printf("%d\n",p->data);
        p = p->prev;
    }
}
void opposite(struct node*start,int p)
{
    struct node*c1;
    struct node*c2;
    c1 = start;
    c2=start;
    while(c1->data!=p)
        c1=c1->next;
    while(c2->data!=p)
        c2=c2->next;
        c2 = c2->next;
        c1 = c1->prev;
        while(c1->data!=c2->data&&c2->next!=c1)
        {
            c1 = c1->prev;
            c2 = c2->next;
        }
        if(c2->next==c1)
            printf("cannot be determined\n");
        else
            printf("%d\n",(c2->data));
}
int main()
{
    int n,i,x,p,del;
    struct node*start;
    start = NULL;
    printf("no of operations you want to perform\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("insert element\n");
        scanf("%d",&x);
        start = insertnode(start,x);
    }
    printf("no you want to delete\n");
    scanf("%d",&del);
    start = hata(start,del);
    printf("\n\n");
    display1(start);
    printf("\n\n");
    display2(start);
    printf("no whose opposite no you want to find\n");
    scanf("%d",&p);
    opposite(start,p);
    return 0;
}
