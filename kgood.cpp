#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
map<int,int> f;
map<int,int> fr;
map<char,int> :: iterator itr;
int main()
{
    int t,k,i,ls,mn,mx;
    string s;
    cin>>t;
    while(t--)
    {
        m.clear();
        f.clear();
        fr.clear();
        int ans = 0;
        mn = 12345678;
        mx = 0;
        cin>>s>>k;
        ls = s.length();
        for(i=0;i<ls;i++)
        {
            m[s[i]]++;
        }
        for(itr=m.begin();itr!=m.end();itr++)
        {
            if(itr->second <= mn)
                mn = itr->second;
            if(itr->second >= mx)
                mx = itr->second;
            f[itr->second] = f[itr->second] + 1;
        }
        //cout<<" mn = "<<mn<<" mx = "<<mx<<endl;
        if(mx - mn <= k)
        {
            cout<<0<<endl;
        }
        else
        {
            for(itr=m.begin();itr!=m.end();itr++)
            {
                cout<<f[itr->second]<<" ";
                if(itr->second > k+1)
                {
                    fr[1] = fr[1] + f[itr->second];
                    mn = fr[1];
                }
            }
            for(i=2;i<=mx;i++)
            {
                fr[i] = fr[i] + f[i-1] + fr[1] - f[k + i];
                if(fr[i] <= mn)
                    mn = fr[i];
            }
            cout<<mn<<endl;
        }
    }
    return 0;
}

