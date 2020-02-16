#include<bits/stdc++.h>
using namespace std;
int tree[1000],a[1000],i;
void build(int node,int start,int end)
{
    if(start == end)
    {
        if(a[start]%3 == 0)
            tree[node] = 1;
        else tree[node] = 0;
    }
    else
    {
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}
void modify( int node, int start,int end,int l)
{
    if(start == end)
    {
        a[start]++;
        if(a[start]%3 == 0)
            tree[node] = 1;
        else tree[node] = 0;
    }
    else
    {
        int mid = (start+end)/2;
        if(l>=start && l<=mid)
        {
            modify(2*node,start,mid,l);
        }
        else modify(2*node+1,mid+1,end,l);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int query(int node,int start,int end, int l,int r)
{
    if(l>end || r<start)
        return 0;
    if(l<=start && r>=end)
        return tree[node];
    int mid = (start + end)/2;
    int p1 = query(2*node,start,mid,l,r);
    int p2 = query(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}
int main()
{
    long long int n,q,i,op,x,y,start,end,node=1,l;
    cin>>n>>q;
    for(i=0;i<n;i++)
        a[i] = 0;
    start=0,end=n-1;
    build(node,start,end);
    while(q--)
    {
        cin>>op>>x>>y;
        if(op==0)
        {
            for(l=x;l<=y;l++)
            modify(node,start,end,l);

        }
        else
        {
            cout<<query(node,start,end,x,y)<<endl;
        }
    }
    return 0;
}
