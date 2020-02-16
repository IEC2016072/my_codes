// dry run the program
#include<stdio.h>
void mergesort(int a[],int low,int high)
{
    int mid = (low+high)/2;
    if(low<high)
    {
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[],int low,int mid,int high)
{
    int nl = mid - low +1,nr = high - mid,l[1000],r[1000],i,j,k;
    for(i=low;i<=mid;i++)
        l[i-low] = a[i];
    for(i=mid+1;i<=high;i++)
        r[i-mid-1] = a[i];
    l[nl+1] = 99999,r[nr+1] = 99999;
    i=0,j=0,k=0;
    for(k=0;k<=high - low + 1;k++)
    {
           if(l[i]<=r[j])
           {
                a[k] = l[i];
                i++;
           }
           else
            {
                a[k] = r[j];
                j++;
            }
    }
}
int main()
{
    int n,i,a[100],low,high;
    scanf("%d",&n);
    low = 0,high = n-1;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,low,high);
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}
