#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int x=0,l,i;
    string s;
    cin>>s;
    for(l=0;s[l]!='\0';l++);
    for(i=0;i<l-1;i++)
    {
        if((s[i] == '1') || (s[i]=='2' && s[i+1]=='0'))
            x++;
    }
    cout<<2*x + 1;
}
