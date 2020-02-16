#include<stdio.h>
int main()
{
    int a[1000],n,i,j,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
        sum = sum + (a[i]^a[j]);
      //  printf("%d\n",sum);
        }
    printf("%d",sum);
    return 0;
}
