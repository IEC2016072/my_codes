// code is incomplete @codoman
#include<bits/stdc++.h>
using namespace std;
const int as = 26;
struct trienode
{
    struct trienode *children[as];
    bool isendofword;
};
struct trienode*getnode()
{
    cout<<"get node"<<endl;
    struct trienode* pnode;
    for(int i=0;i<=as;i++)
    {
        pnode->children[i] = NULL;
    }
    pnode->isendofword = false;
    return pnode;
}
void insertt(struct trienode*root,char str[100])
{
    cout<<"aa"<<endl;
    struct trienode* pcrawl = root;
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        int index = str[i] - 'a';
        if(pcrawl->children[index] == NULL)
        {
            pcrawl->children[index] = getnode();
            pcrawl = pcrawl->children[index];
        }
    }
    pcrawl->isendofword = true;
    cout<<"inside insert function"<<endl;
}
int search(struct trienode*root,string strn)
{
    struct trienode*pcrawl = root;
    int i,index;
    for(i=0;i<strn.length();i++)
    {
        index = strn[i] - 'a';
        if(pcrawl->children[index] != NULL)
        {
            pcrawl = pcrawl->children[index];
        }
        else return 0;
    }
    return 1;
}
int main()
{
    struct trienode* root = getnode();
    int n,i;
    char keys[100][100],strn[100];
    cout<<"enter no. of strings"<<endl;
    cin>>n;
    cout<<"enter strings\n";
    for(i=0;i<n;i++)
    {
        cin>>keys[i];
        insertt(root,keys[i]);
    }
    cout<<"enter string name to be searched\n";
    cin>>strn;
    //cout<<search(root,strn);
}
