#include<bits/stdc++.h>
using namespace std;
set<char[1000]> st;
set<char[1000]> :: iterator it;
int main()
{
    char s[1000];
    s[0]='a';
    s[1]='\0';
    st.insert(s);
//    st.insert("asfg");
  //  st.insert("A");
    cout<<st.size()<<endl;
    for(it = st.begin();it!=st.end();it++)
    {
        //cout<<it<<endl;
        cout<<*it;
    }
}
