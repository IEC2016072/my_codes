#include<stdio.h>
#include<stdlib.h>
struct list
{
    int data;
    struct list*nextv;
    struct list*nexte;
};
struct list*findvertex(struct list*start,int u)
{
    printf("aa\n");
    struct list*p;
    p = start;
    while(p!=NULL)
    {
        if(p->data == u)
            return(p);
        p = p->nextv;
    }
    return(p);
}
struct list*insertvertex(struct list*start,int v)
{
    struct list*p,*q,*temp = (struct list*)malloc(sizeof(struct list));
    temp->data = v;
    temp->nextv = NULL;
    temp->nexte = NULL;
    q = start;
    while(q!=NULL)
    {
        if(q->data == v)
        {
            printf("vertex already exist\n");
            return(start);
        }
        q = q->nextv;
    }
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        p = start;
        while(p->nextv!=NULL)
            p = p->nextv;
        p->nextv = temp;
    }
    return(start);
}
void insertedge(struct list*start,int u,int v)
{
    struct list*locu,*locv,*p,*temp = (struct list*)malloc(sizeof(struct list));
    locu = findvertex(start,u);
    locv = findvertex(start,v);
    if(locu == NULL || locv == NULL)
    {
        printf("not possible\n");
    }
    else
    {
        p = locu;
        while(p->nexte != NULL)
            p = p->nexte;
        temp->data = v;
        temp->nextv = NULL;
        temp->nexte = NULL;
        p->nexte = temp;
    }
}
void display(struct list*start)
{
    struct list*p,*q;
    p = start;
    while(p!=NULL)
    {
        q = p;
        while(q!=NULL)
        {
            printf("%d-> ",q->data);
            q = q->nexte;
        }
        printf("\n");
        p = p->nextv;
    }
}
struct list*deleteedge(struct list*start,int u,int v)
{
    struct list*q;
    q = findvertex(start,u);
    printf("bb\n");
    while(q->nexte != NULL)
    {
        printf("cc\n");
        if(q->nexte->data == v)
        {
            printf("dd\n");
            q->nexte = q->nexte->nexte;
            break;
        }
        q = q->nexte;
    }
    return(start);
}
struct list*deletevertexv(struct list*start,int v)
{
    struct list*p = start;
    if(start->data == v)
        start = start->nextv;
    else
    {
        while(p->nextv!=NULL)
        {
            if(p->nextv->data == v)
            {
                p->nextv = p->nextv->nextv;
                break;
            }
            p = p->nextv;
        }
    }
    return(start);
}
struct list*deletevertexh(struct list*start,int v)
{
    printf("aa\n");
    struct list*p = start,*q;
    while(p!=NULL)
    {
        printf("%dasd\n",p->data);
        q = p;
        while(q->nexte!=NULL)
        {
            printf("cc\n");
            printf("\n%d\n",q->data);
            if(q->nexte->data == v)
            {
                q->nexte = q->nexte->nexte;
                break;
            }
            q = q->nexte;
        }
        p = p->nextv;
    }
    return(start);
}
int main()
{
    int c,u,v;
    struct list*start = NULL;
    while(1)
    {
        printf(" enter your choice\n1-insert vertex\n2-insert edge\n3-delete edge\n4-delete vertex\n ");
        scanf("%d",&c);
        if(c == 1)
        {
            printf(" enter vertex to be added\n");
            scanf("%d",&v);
            start = insertvertex(start,v);
        }
        else if(c==2)
        {
            printf("enter 1st and 2nd vertex to insert an edge\n");
            scanf("%d%d",&u,&v);
            insertedge(start,u,v);
            display(start);
        }

        else if(c==3)
        {
            printf("enter source and destination vertex to delete\n");
            scanf("%d%d",&u,&v);
            start = deleteedge(start,u,v);
            display(start);
        }
        else
        {
            printf("enter vertex to be deleted\n");
            scanf("%d",&v);
            start = deletevertexv(start,v);
            start = deletevertexh(start,v);
           // display(start);
           // printf("bb\n");


         //   printf("dd\n");
            display(start);
        }
    }
}
