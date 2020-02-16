#include <iostream>
#include <map>
#include <iterator>

using namespace std;
int main()
{
    map < int , int > m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));
    m1.insert(pair<int,int>(5,50));
    m1.insert(pair<int,int>(6,60));

    map<int,int>::iterator itr;
    for(itr=m1.begin();itr!=m1.end();++itr)
    {
        cout<<'\t'<<itr->first;
        cout<<'\t'<<itr->second;
    }
    cout<<endl;
    map<int,int> m2(m1.begin(),m1.end());
    for(itr=m2.begin();itr!=m2.end();++itr)
    {
        cout<<'\t'<<itr->first;
        cout<<'\t'<<itr->second;
    }
    cout<<endl;
    m2.erase(m2.begin(),m2.find(3));
    for(itr=m2.begin();itr!=m2.end();++itr)
    {
        cout<<'\t'<<itr->first;
        cout<<'\t'<<itr->second;
    }
    return 0;
}
