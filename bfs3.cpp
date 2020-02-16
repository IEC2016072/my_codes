#include<bits/stdc++.h>
using namespace std;
int ans=0,visit[1000005],i,a[1000005];
vector<int> v[1000005];
void bfs(int x)
{
    visit[x] = 1;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        x = q.front();
        //cout<<" x = "<<x<<endl;
        q.pop();
        for(i= 0;i!=v[x].size();i++)
        {
            if((a[x] - a[v[x][i]]) > ans)
                ans = a[x] - a[v[x][i]];
            if(a[x] > a[v[x][i]])
                a[v[x][i]] = a[x];
            if(visit[v[x][i]] == 0)
            {
                q.push(v[x][i]);
                visit[v[x][i]] = 1;
            }
        }
    }
}
int main()
{
    int n,x,top;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x != -1)
            v[x].push_back(i);
        if(x == -1)
            top = i;
    }
    bfs(top);
    cout<<ans;
    return 0;
}

