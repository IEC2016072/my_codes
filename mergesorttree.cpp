#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector <ll> tree[1000];
ll a[1000];
void merg(ll node1,ll node2,ll node3)
{
    ll i=0,j=0,k=0;
    ll l2 = tree[node2].size(),l3 = tree[node3].size();
    while(i<l2 && j<l3)
    {
        if(tree[node2][i] <= tree[node3][j])
        {
            tree[node1].push_back(tree[node2][i]);
            i++;
        }
        else
        {
            tree[node1].push_back(tree[node3][j]);
            j++;
        }
    }
    while(i<l2)
    {
        tree[node1].push_back(tree[node2][i]);
        i++;
    }
    while(j<l3)
    {
        tree[node1].push_back(tree[node3][j]);
        j++;
    }
}
void build(ll start,ll en , ll node)
{
    if(start == en)
    {
        tree[node].push_back(a[start]);
    }
    else
    {
        ll mid = ( start + en )/2;
        build(start,mid,2*node);
        build(mid+1,en,2*node+1);
        merg(node,2*node,2*node+1);
    }
}
int main()
{
    ll n,i,start,en,node;
    cin>>n;
    start =0 ,en = n-1,node=1;
    for(i=0;i<n;i++)
        cin>>a[i];
    build(start,en,node);
    ll x = tree[1].size();
    for(i=0;i<x;i++)
    {
        cout<<tree[1][i]<<" ";
    }
}

