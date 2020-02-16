#include<bits/stdc++.h>
using namespace std;
queue<int> q;
long long int n,c,a[1000][1000],flag[1000],m,x,y,i,j,ma;
void bfs( long long int i )
{
    //cout<<"AA"<<endl;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
       // cout<<n<<" "<<x<<endl;
        for(j=1;j<=n;j++)
        {
           // cout<<"J"<<j<<endl;
            if(a[x][j] == 1 && flag[j] == 0)
            {
                q.push(j);
                flag[j] = 1;
                c++;
                //cout<<"BB"<<endl;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        flag[i] = 0;
        for(j=1;j<=n;j++)
        {
            a[i][j] = 0;
        }
    }
    while(m--)
    {
        cin>>x>>y;
        a[x][y] = 1;
    }
    ma  = 0;
    for(i=1;i<=n;i++)
    {
        if(flag[i] == 0)
        {
            c = 1;
            q.push(i);
            for(j=1;j<=n;j++)
                flag[j] = 0;
            flag[i] = 1;
            bfs(i);
            //cout<<c<<endl;
            if(c>ma)
                ma = c;
        }
    }
    cout<<ma;
}

