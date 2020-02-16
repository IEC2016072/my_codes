#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node*lc;
    struct node*rc;
};
int main()
{
    int n,q,x,y;
    string s;
    struct node*root = NULL,*temp = (struct node*)malloc(sizeof(struct node));
    temp->val = 1;
    temp->lc = NULL;
    temp->rc = NULL;
    cin>>n>>q;
    while(n>1)
    {
        n--;
        cin>>x>>y>>s;
    }
}
