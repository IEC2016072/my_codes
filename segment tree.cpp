#include<bits/stdc++.h>
using namespace std;
int tree[1005],i,j,a[1005];
void build(int node,int start, int end)
{
    if(start == end)
    {
        if(a[start]%2 == 0)
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
void modify( int node, int start,int end,int idx, int val)
{
    if(start == end)
    {
        a[idx] = val;
        if(a[idx]%2 == 0)
            tree[node] = 1;
        else tree[node] = 0;
    }
    else
    {
        int mid = (start + end)/2;
        if(idx>=start && idx<=mid)
        {
            modify(2*node,start,mid,idx,val);
        }
        else modify(2*node +1,mid+1,end,idx,val);
        tree[node] = tree[2*node] + tree[2*node + 1];
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
    int n,q,x,y,mode,node=1,start=1,end,z;
    cin>>n;
    end = n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    build(node,start,end);
    for(i=1;i<=11;i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    cin>>q;
    while(q--)
    {
        cin>>mode>>x>>y;
        if(mode == 0)
        {
            modify(node,start,end,x,y);
            for(i=1;i<=11;i++)
                cout<<tree[i]<<" ";
            cout<<endl;
        }
        else if(mode == 1)
        {
            z = query(node,start,end,x,y);
            cout<<z<<endl;
        }
        else
        {
            z = query(node,start,end,x,y);
            cout<<(y-x+1-z)<<endl;
        }
    }
    return 0;
}

