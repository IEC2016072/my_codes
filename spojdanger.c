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
};
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
int main()
{
    char s[100];
    struct node*start = NULL,*p,*r;
    int i,x,a,b,c;
    while(1)
    {
    scanf("%s",s);
    if(s[0] == '0' && s[1] == '0' && s[2] == 'e' &&s[3] == '0')
        break;
    a = s[0] - 48,b = s[1] - 48,c = s[3] - 48;
    x = a*10;
    x = x + b;
    for(i=1;i<=c;i++)
        x = x*10;
    for(i=1;i<=x;i++)
        start = insertnode(start,i);
    p = start;
    while(p->next!=p)
    {
        p = p->next;
        r = p->next;
        start = delete(start,p->data);
        p = r;
    }
    printf("%d\n",p->data);
    }
}
