#include<bits/stdc++.h>
using namespace std;
int main()
{
    string send,rec;
    map <char,int> h;
    cin>>send;
    cin>>rec;
    for(int i=0;i<send.length();i++)
    {
        h[send[i]]++;
    }
    for(int i=0;i<rec.length();i++)
    {
        h[rec[i]]--;
    }
    for(int i=0;i<rec.length();i++)
    {
        if(h[rec[i]] > 0) { h[rec[i]] = 0; cout<<rec[i]<<" "; }
    }
}
