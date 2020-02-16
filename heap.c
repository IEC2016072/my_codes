#include<stdio.h>
void swap(int *a,int *b)
{
    printf("ee\n");
    int temp = *a;
    *a = *b;
    *b = temp;
}
void relocate(int heap[],int num,int size)
{
    printf("dd\n");
    int par = size/2;
    while(par>=1 && heap[par]<num)
    {
        heap[size] = heap[par];
        size = par;
        par = size/2;
    }
    heap[size] = num;
}
void insert(int heap[],int num,int *size)
{
    printf("bb\n");
    *size = *size + 1;
    heap[*size] = num;
    relocate(heap,num,*size);
    printf("cc\n");
}
void restoredown(int heap[],int i,int size)
{
    int lchild = 2*i,rchild = lchild + 1;
    int num = heap[i];
    while(rchild<=size)
    {
        if(num>=heap[lchild] && num>=heap[rchild])
        {
            heap[i] = num;
            return;
        }
        else if(heap[lchild] > heap[rchild])
        {
            heap[i] = heap[lchild];
            i = lchild;
        }
        else
        {
            heap[i] = heap[rchild];
            i = rchild;
        }
        lchild = 2*i;
        rchild = lchild + 1;
    }
    if(lchild == size && num<heap[lchild])
    {
        heap[i] = heap[lchild];
        i = lchild;
    }
    heap[i] = num;
}
int delroot(int heap[],int *size)
{
    int max = heap[1];
    heap[1] = heap[*size];
    *size = *size - 1;
    restoredown(heap,1,*size);
    return(max);
}
int main()
{
    int n,i,j,a[100],size,heap[1000],del;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    size = 0;
    for(i=1;i<=n;i++)
    {
        printf("aa\n");
        insert(heap,a[i],&size);
        printf("ff\n");
        for(j=1;j<=size;j++)
        printf("%d ",heap[j]);
        printf("\n");
    }
    del = delroot(heap,&size);
    printf("%d\n",del);
}
