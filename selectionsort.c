#include<stdio.h>
void selectionsort(int a[],int n)
{
    int i,min,pos,j;
     for(i=0;i<n-1;i++)
    {
        min = a[i];
        pos = i;
        for(j=i;j<n;j++)
        {
            if(a[j]<=min)
            {
                min = a[j];
                pos = j;
            }
        }
        a[pos] = a[i];
        a[i] = min;
    }
}
int main()
{
    int n,i,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    selectionsort(a,n);
   for(i=0;i<n;i++)
    printf("%d ",a[i]);

    return 0;
}
