#include<bits/stdc++.h>
using namespace std;
int arr[100005],siz[100005],n,m,i,flag[100005] = {0};
void init()
{
   for(i=1;i<=n;i++)
   {
       arr[i] = i;
       siz[i] = 1;
   }
}
int root(int x)
{
    while(arr[x] != x)
    {
        x = arr[x];
    }
    return x;
}
void unio(int u,int v)
{
    int rootu = root(u);
    int rootv = root(v);
    if(rootu == rootv)
        return;
    if(siz[rootu] > siz[rootv])
    {
        arr[rootv] = arr[rootu];
        siz[rootu] = siz[rootv] + siz[rootu];
    }
    else
    {
        arr[rootu] = arr[rootv];
        siz[rootv] = siz[rootv] + siz[rootu];
    }
}
int main()
{
    int u,v;
    cin>>n>>m;
    init();
    while(m--)
    {
        cin>>u>>v;
        unio(u,v);
    }
    long long int ans = 1;
    ans = (ans*(siz[root(1)]))%1000000007;
    flag[root(1)] = 1;
    for(i=2;i<=n;i++)
    {
        //cout<<siz[root(i)]<<" ";
        if(flag[root(i)] == 0)
        {
            flag[root(i)] = 1;
            ans = (ans*(siz[root(i)]))%1000000007;
        }
    }
    cout<<ans;
}

