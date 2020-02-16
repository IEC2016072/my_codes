#include<stdio.h>

void merge(int a[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    int x[n1],y[n2];
    printf("x : ");
    for(i=0;i<n1;i++)
    {
        x[i] = a[l+i];
        printf("%d ",x[i]);
    }
    printf("\n: ");
    for(i=0;i<n2;i++)
    {
        y[i] = a[m+1+i];
        printf("%d ",y[i]);
    }
    printf("\n");
    i=0;j=0;k=l;

    while(i<n1 && j<n2)
    {
        if(x[i]<=y[j])
        {
            a[k] = x[i];
            i++;
        }
        else
        {
            a[k] = y[j];
            j++;
        }
        k++;
    }
     while (i < n1)
    {
        a[k] = x[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        a[k] = y[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int r)
{
    if( l<r )
    {
        int m= l + (r-l)/2;

        printf("l=%d r=%d m=%d \n",l,r,m);
        mergesort(a,l,m);
        mergesort(a,m+1,r);

        merge(a,l,m,r);
    }
}

int main()
{
    int n,a[100],i,j;
    printf("How many Elements you want in array? ");
    scanf("%d",&n);
    printf("Enter %d elements",n);
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The Sorted array is : ");
    mergesort(a,0,n-1);
    for(i=0 ; i<n ; i++)
    {
        printf("%d ",a[i]);
    }
}
