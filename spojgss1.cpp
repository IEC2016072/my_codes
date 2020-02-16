#include<bits/stdc++.h>
using namespace std;
long long int tree[1000],a[1000],mx,c=0;
void build(long long int node,long long int start,long long int end)
{
    c++;
    if(start==end)
    {
        tree[node] = a[start];
    }
    else
    {
        long long int mid = (start + end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}
void query(long long int node,long long int start,long long int end,long long int l,long long int r)
{
    //cout<<"LL"<<endl;
    if(l>end || r<start || node>c)
        return;
    else if(l<=start && r>=end)
    {
        if(tree[node]>=mx)
            mx = tree[node];
        long long int mid = (start+end)/2;
        query(2*node,start,mid,l,r);
        query(2*node+1,mid+1,end,l,r);
    }
    else
    {
        long long int mid = (start+end)/2;
        query(2*node,start,mid,l,r);
        query(2*node+1,mid+1,end,l,r);
    }
    return;
}
int main()
{
    long long int n,i,j,x,y,start,end,node=1,m;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    start=1,end=n;
    build(node,start,end);
    /*c0out<<"size "<<c<<endl;
    for(i=1;i<=5;i++)
        cout<<tree[i]<<" ";
    cout<<endl;*/
    scanf("%lld",&m);
    while(m--)
    {
        scanf("%lld%lld",&x,&y);
        mx = a[x];
        query(node,start,end,x,y);
        printf("%lld\n",mx);
    }
    return 0;
}

