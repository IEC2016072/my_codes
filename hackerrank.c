#include<stdio.h>
void push(char stack[1000],char x,int*top)
{
    *top = *top + 1;
    stack[*top]=x;
    printf("%c\n",stack[*top]);
}
int main()
{
    int n,i,l,j,top=0,flag;
    char s[1000],stack[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        flag=0;
        top=-1;
        scanf("%s",s);
        for(l=0;s[l]!='\0';l++);
        for(j=0;j<l;j++)
        {
        if(s[j]=='['||s[j]=='{'||s[j]=='(')
            push(stack,s[j],&top);
            if(s[j]==']')
            {
                if(stack[top]=='[')
                  printf("%d\n",--top);
            else
            {
                flag=1;
                printf("No\n");
                break;
            }
            }
             if(s[j]=='}')
            {
                if(stack[top]=='{')
                     printf("%d\n",--top);
            else
            {
                flag=1;
                printf("No\n");
                break;
            }
                }
             if(s[j]==')')
            {
                if(stack[top]=='(')
                     printf("%d\n",--top);
            else
            {
                flag=1;
                printf("No\n");
                break;
            }
            }
        }
            if(flag==0)
            {
            if(top==-1)
                printf("Yes\n");
                else printf("No\n");
            }
    }
    return 0;
}
