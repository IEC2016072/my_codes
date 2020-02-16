#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,x,y,j;
        vector< pair<int,int> > v;
        int mx = INT_MIN;
        int dp[n+1];
        for(i=0;i<n;i++)
        {
            x=p[i].first,y=p[i].second;
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(),v.end());
        for(i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        for(i=0;i<n;i++) dp[i] = 1;
        for(i=1;i<v.size();i++)
        {
            for(j=i-1;j>=0;j--)
            {
                x = v[j].second,y = v[i].first;
                if(y>x) dp[i] = max(dp[i],dp[j]+1);
            }
            mx = max(mx,dp[i]);
        }
        return mx;
    }
}
