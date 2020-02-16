#include<stdio.h>
void bubblesort(int a[],int n)
{
    int i,j,x,temp;
    for(i=0;i<n-1;i++)
    {
        x=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                x++;
            }
        }
        if(x==0)
            break;
    }
    printf("sorted list is :\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    int n,i,a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    bubblesort(a,n);
    return 0;
}
