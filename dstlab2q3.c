#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char a[100];
    char b[100];
    int pval,han;
    struct node*next;
};
struct node*insertnode(struct node*start,char s1[],char s2[],int x)
{
    printf("cc\n");
    struct node*temp,*temp2,*p;
    temp = (struct node*)malloc(sizeof(struct node));
    if(start == NULL)
    {
        printf("dd\n");
        strcpy(temp->a,s1);
        strcpy(temp->b,s2);
        temp->pval = x;
        temp->han = 0;
        start = temp;
        start->next = start;
        printf("ee\n");
    }
    else
    {
        printf("gg\n");
        p = start;
        while(1)
        {
           // printf("1\n");
            if(strcmp(s2,p->a) == 0)
            {
                printf("2\n");
                strcpy(temp->a,s1);
                printf("3\n");
                strcpy(temp->b,s2);
                printf("4\n");
                temp->pval = x;
                temp->han = 0;
                printf("5\n");
                temp2 = p->next;
                printf("6\n");
                p->next = temp;
                printf("7\n");
                temp->next = temp2;
                printf("hh\n");
                break;
            }
            p = p->next;
        }
    }
    return(start);
}
void display(struct node*start)
{
    struct node*p = start;
    while(p->next!=start)
    {
        printf("%s %s %d\n",p->a,p->b,p->pval);
        p = p->next;
    }
    printf("%s %s %d\n",p->a,p->b,p->pval);
}
void player(struct node*start,char s[],int x)
{
    int i,j,min;
    struct node*p,*q,*r;
    p = start;
    while(1)
    {
        if(strcmp(p->a,s)==0)
        {
            p->han = p->han + 1;
            q = p;
            break;
        }
    }
    for(j=0;j<x-1;j++){
    if(q->pval == -1)
    {
         p = q->next;
         r = p;
         min = p->han;
         while(p!=q)
         {
             if(p->han < min )
             {
                 min = p->han;
                 r = p;
             }
             else if(p->han == min && p->pval<= r->pval)
             {
                 min = p->han;
                 r = p;
             }
         }
         if(p->han < min || (p->han == min &&p->pval <= r->pval))
         {
             r = p;
             printf("%s\n",r->a);
         }
    }
    else
    {
        for(i=0;i< p->pval ;i++)
            q = q->next;
        p=q;
        printf("%s\n",q->a);
    }
    }
}
int main()
{
    int m,i,x,q;
    char s1[100],s2[100],s3[100];
    struct node*start = NULL;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("aa\n");
        scanf("%s%s%d",s1,s2,&x);
        printf("bb\n");
        start = insertnode(start,s1,s2,x);
        //display(start);
        printf("ff\n");
    }
    display(start);
    scanf("%d",&q);
    scanf("%s",s3);
    player(start,s3,q);
}
