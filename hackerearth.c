#include<stdio.h>
void push(int stack[],int q,int*top,int*sum)
{
    *top= *top + 1;
    stack[*top]=q;
    *sum= *sum + q;

}
int main()
{
    int n,i,a[1000],top=-1,j=0,x,q,stack[1000],sum=0;
    char s[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d%d",&q,&x);
    for(i=0;i<q;i++)
    {
        scanf("%s",s);
        if(strcmp(s,"Harry")==0)
        {
            push(stack,a[j],&top,&sum);
            j++;
            if(sum==x)
            {
                printf("%d",top+1);
                break;
            }
        }
        if(strcmp(s,"Remove")==0)
        {
            sum=sum-stack[top];
            top--;
        }
    }
    if(sum!=x)
        printf("-1\n");
    return 0;
}
