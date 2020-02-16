#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll x,pos[1000005],lps[1000005];
void computelpsarray(string pat, ll M)
{
    // length of the previous longest prefix suffix
    ll len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    ll i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void kmpsearch(string txt,string pat)
{
    ll la,lb,i,j;
    for(la=0;txt[la]!='\0';la++);
    for(lb=0;pat[lb]!='\0';lb++);
    computelpsarray(pat,lb);
    //cout<<"lps[] = ";
    //for(i=0;i<lb;i++)
     //   cout<<lps[i]<<" ";
    //cout<<endl;
    i=0,j=0;
    while (i < la)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == lb)
        {
            pos[x++] = i-j;
            j = lps[j-1];
        }

        // mismatch after j matches
        else if (i < la && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    if(x == 0)
    {
        cout<<"NOT FOUND"<<endl<<endl;
        return;
    }
    cout<<x<<endl;
    for(i=0;i<x;i++)
        cout<<pos[i] + 1;
    cout<<endl<<endl;
}
int main()
{
    ll t,i;
    string txt,pat;
    cin>>t;
    while(t--)
    {
        x = 0;
        cin>>txt>>pat;
        kmpsearch(txt,pat);
    }
}
