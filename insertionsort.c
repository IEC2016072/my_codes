#include<stdio.h>
void insertionsort(int a[1000],int n)
{
    int i,j,key;
   for(i=1;i<n;i++)
    {
        key = a[i];
        j = i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main()
{
    int n,i,a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertionsort(a,n);

    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}
