
#include<bits/stdc++.h>
using namespace std;
// tree1 = sum,tree2 = prefix sum,tree3 = suffix sum,tree4 = max sum
typedef long long int ll;
ll maxx(ll x,ll y,ll z)
{
    if(x>=y && x>=z)
        return x;
    else if(y>=x && y>=z)
        return y;
    else return z;
}
ll tree1[1000],tree2[1000],tree3[1000],tree4[1000],a[1000];
void build1(ll start,ll en,ll node)
{
    if(start == en)
    {
        tree1[node] = a[start];
    }
    else
    {
        ll mid = (start+en)/2;
        build1(start,mid,2*node);
        build1(mid+1,en,2*node+1);
        tree1[node] = tree1[2*node] + tree1[2*node+1];
    }
}
void build2(ll start,ll en,ll node)
{
    if(start==en)
    {
        tree2[node] = a[start];
    }
    else
    {
        ll mid = (start+en)/2;
        build2(start,mid,2*node);
        build2(mid+1,en,2*node+1);
        if(tree1[2*node] + tree2[2*node+1] > tree2[2*node])
        {
            tree2[node] = tree1[2*node] + tree2[2*node+1];
        }
        else
        {
            tree2[node] = tree2[2*node];
        }
    }
}
void build3(ll start,ll en,ll node)
{
    if(start==en)
    {
        tree3[node] = a[start];
    }
    else
    {
        ll mid = (start+en)/2;
        build3(start,mid,2*node);
        build3(mid+1,en,2*node+1);
        if(tree1[2*node+1] + tree3[2*node] > tree3[2*node+1])
        {
            tree3[node] = tree1[2*node+1] + tree3[2*node];
        }
        else
        {
            tree3[node] = tree3[2*node+1];
        }
    }
}
void build4(ll start,ll en,ll node)
{
    if(start == en)
    {
        tree4[node] = a[start];
    }
    else
    {
        ll mid = (start+en)/2;
        build4(start,mid,2*node);
        build4(mid+1,en,2*node+1);
        ll m = maxx(tree1[2*node],tree1[2*node+1],tree3[2*node]+tree3[2*node+1]);
        tree4[node] = m;
    }
}
ll query(ll start,ll en,ll node,ll l,ll r)
{
    if(start==l && en==r)
        return(tree4[node]);

}
int main()
{
    ll n,i,start,en,node,q,l,r;
    cin>>n;
    start=0,en = n-1,node=1;
    for(i=0;i<n;i++)
        cin>>a[i];
    build1(start,en,node);
    build2(start,en,node);
    build3(start,en,node);
    build4(start,en,node);
    //for(i=1;i<=2*n-1;i++)
      //  cout<<" tree4["<<i<<"] = "<<tree4[i];
    //cout<<endl<<"a[3] "<<a[3]<<"a[4] "<<a[4];
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<query(start,en,node,l,r)<<endl;
    }
}
