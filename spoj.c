#include<stdio.h>
int arr[1005];
void printKMax( int n, int k)
{
    int j, max,i;

    for ( i = 0; i <= n-k; i++)
    {
        max = arr[i];

        for (j = 1; j < k; j++)
        {
            if (arr[i+j] > max)
               max = arr[i+j];
        }
        printf("%d ", max);
    }
}


int main()
{
    int n,k,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&k);
    printKMax( n, k);
    return 0;
}
