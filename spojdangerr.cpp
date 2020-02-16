#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        string s;
        long long int i,x,a,b,c,y=0,x1;
        cin>>s;
        if(s[0] == '0' && s[1] == '0' && s[2] == 'e' &&s[3] == '0')
            break;
        a = s[0] - 48,b = s[1] - 48,c = s[3] - 48;
        x = a*10;
        x = x + b;
        for(i=1;i<=c;i++)
            x = x*10;
        //cout<<x<<endl;
        x1 = x;
        a = 0;
        while(1)
        {
            if(!(x&(x-1)) == 1)
                break;
            else x--;
        }
        //cout<<x2<<" "<<x1<<endl;
        a = 1;
        b = x1 - x;
        a = a + 2*b;
        cout<<a<<endl;
    }
}
