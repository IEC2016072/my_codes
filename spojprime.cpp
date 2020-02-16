#include<iostream>
using namespace std;
int main()
{
    int t,i,x,y,j,prime[100000]={0},b;
    prime[2] = 1;
    for(i=3;i<100000;i++)
    {
        b=0;
        for(j=2;j<i;j++)
        {
            if(i%j == 0)
                b=1;
        }
        if(b == 0)
            prime[i] = 1;
    }
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x>>y;
        for(j=x;j<=y;j++)
        {
            if(prime[j] == 1)
                cout<<j<<endl;
        }
        cout<<endl;
    }
    return 0;
}

