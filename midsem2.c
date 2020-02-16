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
int main()
{
    int n1,n2,i,x;
    struct node*start1 = NULL;
    struct node*start2 = NULL;
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        scanf("%d",&x);
        start1 = insertnode(start1,x);
    }
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        scanf("%d",&x);
        start2 = insertnode(start2,x);
    }
    struct node*p = start1;
    struct node*q = start2;
    int flag = 0;
    while(p!=NULL&&q!=NULL)
    {
        if(p->data == q->data)
        {
            flag = 1;
            p = p->next;
            q = q->next;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if(flag == 0)
        printf("not same\n");
    else
    {
        if(p==NULL&&q!=NULL)
            printf("not same\n");
        else if(p!=NULL&&q==NULL)
            printf("not same\n");
        else printf("same\n");
    }
    return 0;
}
