#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[1000],b[1000],max;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        b[i]=a[i]*(n-i);
    }
    max=b[0];
    for(i=0;i<n;i++)
        if(b[i]>max)
        max=b[i];
    cout<<max<<endl;
    return 0;
}
