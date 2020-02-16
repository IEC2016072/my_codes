#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[1000][1000],b[1000],f[1000],x,y,flag[1000][1000],total,z,flg[1000];
queue<int> qi,qj;
void bfs()
{
    while(!qi.empty() && !qj.empty())
    {
        x = qi.front();
        qi.pop();
        y = qj.front();
        qj.pop();
        if(a[x+1][y] == 1 && flag[x+1][y] == 0)
        {
            qi.push(x+1);
            qj.push(y);
            flag[x+1][y] = 1;
            b[z]++;
        }
        if(a[x-1][y] == 1 && flag[x-1][y] == 0)
        {
            qi.push(x-1);
            qj.push(y);
            flag[x-1][y] = 1;
            b[z]++;
        }
        if(a[x][y+1] == 1 && flag[x][y+1] == 0)
        {
            qi.push(x);
            qj.push(y+1);
            flag[x][y+1] = 1;
            b[z]++;
        }
        if(a[x][y-1] == 1 && flag[x][y-1] == 0)
        {
            qi.push(x);
            qj.push(y-1);
            flag[x][y-1] = 1;
            b[z]++;
        }
    }
}
int main()
{
    while(1)
    {
        f[1000] = {0};
        z = -1;
        x = 0;
        total = 0;
        cin>>n>>m;
        if(n == 0 && m == 0)
            break;
        b[1000] = {0};
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>a[i][j];
                flag[i][j] = 0;
            }
        }
        for(i=0;i<=n+1;i++)
        {
            a[i][0] = 0;
            a[i][m+1] = 0;
        }
        for(i=0;i<=m+1;i++)
        {
            a[0][i] = 0;
            a[n+1][i] = 0;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(flag[i][j] == 0 && a[i][j] == 1)
                {
                    z++;
                    total++;
                    flag[i][j] = 1;
                    b[z]++;
                    qi.push(i);
                    qj.push(j);
                    bfs();
                }
            }
        }
        sort(b,b+z+1);
        for(i=0;i<=z;i++)
        {
            if(f[b[i]] == 0)
            {
                for(j=0;j<=z;j++)
                {
                    if(b[i] == b[j])
                    {
                        f[b[i]]++;
                    }
                }
            }
        }
        flg[z+2] = {0};
        cout<<total<<endl;
        for(i=0;i<=z;i++)
        {
            if(flg[b[i]] == 0)
            {
                cout<<b[i]<<" "<<f[b[i]]<<endl;
                flg[b[i]] = 1;
            }
        }
    }
    return 0;
}

