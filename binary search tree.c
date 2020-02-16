#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*lchild;
    struct node*rchild;
};
struct node*insert(struct node*root,int ikey)
{
    struct node*ptr,*temp,*par;
    ptr = root;
    par = NULL;
    while(ptr!=NULL)
    {
        par = ptr;
        if(ikey < ptr->data)
            ptr = ptr->lchild;
        else ptr = ptr->rchild;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ikey;
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(par == NULL)
        root = temp;
    else if(ikey < par->data)
        par->lchild = temp;
    else par->rchild = temp;
    return(root);
}
void preorder(struct node*root)
{
    struct node*p = root;
    if(p == NULL)
        return;
    printf("%d\n",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
}
void inorder(struct node*root)
{
    struct node*p = root;
    if(p == NULL)
        return;
    inorder(p->lchild);
    printf("%d\n",p->data);
    inorder(p->rchild);
}
void postorder(struct node*root)
{
    struct node*p = root;
    if(p == NULL)
        return;
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d\n",p->data);
}
struct node*casea(struct node*root,struct node*ptr,struct node*par)
{
    if(par == NULL)
        root = NULL;
    else if(ptr == par->lchild)
        ptr->lchild = NULL;
    else ptr->rchild = NULL;
    return(root);
}
struct node*caseb(struct node*root,struct node*ptr,struct node*par)
{
    if(par == NULL)
    {
        if(ptr->lchild!=NULL)
            root = ptr->lchild;
        else root = ptr->rchild;
    }
    else if(ptr == par->lchild)
    {
        if(ptr->lchild!=NULL)
            par->lchild = ptr->lchild;
        else par->lchild = ptr->rchild;
    }
     else if(ptr == par->rchild)
    {
        if(ptr->lchild!=NULL)
            par->rchild = ptr->lchild;
        else par->rchild = ptr->rchild;
    }
    return(root);
}
struct node*casec(struct node*root,struct node*ptr,struct node*par)
{
    struct node*succ,*parsucc;
    succ = ptr->rchild;
    while(succ->lchild != NULL)
    {
        parsucc = succ;
        succ = succ->lchild;
    }
    ptr->data = succ->data;
    if(succ->lchild == NULL && succ ->rchild == NULL)
        root = casea(root,ptr,par);
    else root = caseb(root,ptr,par);
    return(root);
}
struct node*delete(struct node*root,int dkey)
{
    struct node*ptr,*par;
    ptr = root;
    par = NULL;
    while(ptr!=NULL)
    {
        if(ptr->data == dkey)
            break;
        par = ptr;
        if(dkey < ptr->data)
            ptr = ptr->lchild;
        else ptr = ptr->rchild;
    }
    if(ptr->lchild != NULL && ptr->rchild != NULL)
        root = casec(root,ptr,par);
    else if(ptr->lchild != NULL && ptr->rchild == NULL)
        root = caseb(root,ptr,par);
    else if(ptr->lchild == NULL && ptr->rchild != NULL)
        root = caseb(root,ptr,par);
    else root = casea(root,ptr,par);
    return(root);
}
int main()
{
    int ikey,dkey;
    struct node*root = NULL;
    while(1)
    {
        printf("enter node(-1 to quit) to insert\n ");
        scanf("%d",&ikey);
        if(ikey == -1)
            break;
        root = insert(root,ikey);

       // inorder(root);
       // postorder(root);
    }
     preorder(root);
     printf("\n");
     inorder(root);
     printf("\n");
     postorder(root);
     printf("\n");
     printf("enter the node to be deleted\n");
     scanf("%d",&dkey);
     root = delete(root,dkey);
     preorder(root);
}
