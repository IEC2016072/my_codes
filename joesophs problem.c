#include<stdio.h>
struct node
{
    int data;
    struct node*next;
};
struct node*insertnode(struct node*start,int x)
{
    struct node*temp;
    struct node*p = start;
    if(start == NULL)
    {
        temp = (struct node*)malloc(sizeof (struct node));
        temp->data = x;
        start = temp;
        temp->next = start;
        return(start);
    }
    else
    {
        while(p->next!=start)
            p = p->next;
         temp = (struct node*)malloc(sizeof (struct node));
         temp->data = x;
         temp->next = start;
         p->next = temp;
         return(start);
    }
}
/*struct node*remove(struct node*start,int del)
{
    struct node* tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp=start;
    struct node* p;
    p =(struct node*)malloc(sizeof(struct node));
    p = start;
    if(p->data == del)
    {
        start = p->next;
        return(start);
      //  return (start);
    }
    else
    {
        while(p->next!=start)
        {
            if(p->next->data == del)
            {
                tmp = p->next;
                p->next = tmp->next;
                return(p->next);
              //  return (start);
            }
            else p = p->next;

        }
    }

}*/
void wheel(struct node*start,int a)
{
    int i,b;
    struct node*p;
    struct node*q;
    q = start;
    p = start;
    while(p!=p->next)
    {
    for(i=1;i<=a;i++)
    {
        p = p->next;
        if(i<a)
            q = q->next;
    }
    q->next = p->next;
    if(p->next == p)
        break;
    }
    printf("%d\n",p->data);
}

void display(struct node*start)
{
    struct node*p = start;
    while(p->next!=start)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
}
int main()
{
    int n,a,i,x;
    struct node*start;
    start = NULL;
    printf("enter no of elements in circular linked list\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter element you want to insert\n");
        scanf("%d",&x);
        start = insertnode(start,x);
    }
    printf("the elements in your linked list are:\n");
    display(start);
    printf("enter joesophs special number\n");
    scanf("%d",&a);
    wheel(start,a);
    return 0;
}
