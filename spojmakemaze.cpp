#include<bits/stdc++.h>
using namespace std;
int t,n,m,i,j,c,flag[1000][1000],x,y;
char a[1000][1000];
queue<int> qi,qj;
void bfs()
{
    while(!qi.empty() && !qj.empty())
    {
        x = qi.front();
        y = qj.front();
        qi.pop();
        qj.pop();
        if(a[x+1][y] == '.' && flag[x+1][y] == 0)
        {
               if((x+1) == 1 || (x+1) == n || y == 1 || y == m)
                        c++;
               flag[x+1][y] = 1;
               qi.push(x+1);
               qj.push(y);
        }
        if(a[x-1][y] == '.' && flag[x-1][y] == 0)
        {
               if((x-1) == 1 || (x-1) == n || y == 1 || y == m)
                        c++;
               flag[x-1][y] = 1;
               qi.push(x-1);
               qj.push(y);
        }
        if(a[x][y+1] == '.' && flag[x][y+1] == 0)
        {
               if((x) == 1 || (x) == n || (y+1) == 1 || (y+1) == m)
                        c++;
               flag[x][y+1] = 1;
               qi.push(x);
               qj.push(y+1);
        }
        if(a[x][y-1] == '.' && flag[x][y-1] == 0)
        {
               if((x) == 1 || (x) == n || (y-1)== 1 || (y-1) == m)
                        c++;
               flag[x][y-1] = 1;
               qi.push(x);
               qj.push(y-1);
        }
}
}
int main()
{
    int fg = 0;
    cin>>t;
    while(t--)
    {
        fg = 0;
        c = 0;
        cin>>m>>n;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>a[i][j];
            }
        }
        for(i=0;i<=m+1;i++)
        {
            for(j=0;j<=n+1;j++)
            {
                flag[i][j] = 0;
            }
        }
        for(j=0;j<=n+1;j++)
        {
            a[0][j] = 'a';
            a[m+1][j] = 'a';
        }
        for(i=0;i<=m+1;i++)
        {
            a[i][0] = 'a';
            a[i][n+1] = 'a';
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(flag[i][j] == 0 && a[i][j] == '.')
                {
                    if(i==1 || i==m || j==1 || j==n)
                        c++;
                    flag[i][j] = 1;
                    qi.push(i);
                    qj.push(j);
                    bfs();
                    if(c == 1)
                    {
                        cout<<"invalid"<<endl;
                        fg = 1;
                        break;
                    }
                }
            }
            if(fg == 1)
                break;
        }
        if(c == 2 && fg == 0)
            cout<<"valid"<<endl;
        else if(c!=2 && fg == 0)
            cout<<"invalid"<<endl;
    }
    return 0;
}

