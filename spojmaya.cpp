#include<bits/stdc++.h>
using namespace std;
long long int power(long long int x,long long int n)
{
    long long int val = 1,i;
    for(i=1;i<=n-1;i++)
    {
        val = 20*val;
    }
    if(n>=3)
    {
        val = val*360;
        val = val/400;
    }
    return (val*x);
}
int main()
{
    long long int n,x,y,i;
    string s;
    while(1)
    {
        cin>>n;
        y = 0;
        if(n == 0)
            break;
        while(n>0)
        {
            getline(cin,s);
            cout<<"aa"<<endl;
            x = 0;
            for(i=0;s[i]!='\0';i++)
            {
                if(s[i] == '.')
                    x++;
                else if(s[i] == '-')
                    x = x+5;
                else if(s[i] == 'S')
                {
                    x = 0;
                    break;
                }
            }
            y = y + power(x,n);
            n--;
        }
    cout<<"bb "<<y<<endl;
}
}

