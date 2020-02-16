#include<iostream>
using namespace std;
int binarysearch(int a[],int n,int x)
{
    int low =0 ,high = n - 1,mid,result = -1;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(a[mid] == x)
        {
            result = mid;
            break;
        }
        else if(a[mid]<=a[high])
        {
            if(x>a[mid]&&x<a[high])
                low = mid +1;
            else high = mid -1;
        }
        else if(a[mid]>a[low])
        {
            if(x<a[mid]&&x>a[low])
                high = mid - 1;
            else low = mid + 1;
        }
        cout<<result<<endl;
    }
    return (result);
}
int main()
{
    int n,i,a[100],x,r;
    cout<<"no of elements"<<endl;
    cin>>p;
    cout<<"elements of array"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"element you want to search"<<endl;
    cin>>x;
    r = binarysearch(a,n,x);
    if(r == -1)
        cout<<"not found"<<endl;
    else cout<<"found at index "<<r;
    return 0;
}
