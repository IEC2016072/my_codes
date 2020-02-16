#include<stdio.h>
void quicksort(int a[],int start,int end)
{
    int pindex;
    if(start<end)
    {
        pindex = partition(a,start,end);
        quicksort(a,start,pindex-1);
        quicksort(a,pindex+1,end);
    }
}
int partition(int a[],int start,int end)
{
    int pivot,i;
    pivot = a[end];
    int pindex = start;
    for( i = start;i<=end-1;i++)
    {
        if(a[i]<=pivot)
        {
            swap(&a[i],&a[pindex]);
            pindex = pindex + 1;
        }
    }
   // printf("%d %d\n",a[pindex],a[end]);
    swap(&a[pindex],&a[end]);
    printf("%d %d\n",a[pindex],a[end]);
    return(pindex);
}
void swap(int* a,int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n,i,a[1000];
    printf("no of elements in the array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int start = 0,end = n-1;
    quicksort(a,start,end);
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}
