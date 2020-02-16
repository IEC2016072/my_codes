#include <iostream>
using namespace std;

int main() {
    long long int n,i,j,k;
    cin>>n;
    long long int arr[n],ans=0;

    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<32;i++)
    {
        k=0;
        for(j=0;j<n;j++)
            if((arr[j] & (1<<i)))
                k++;
        if(k*(n-k)>0)
            ans+=(1<<i);
    }
    cout<<ans<<endl;
    return 0;
}

