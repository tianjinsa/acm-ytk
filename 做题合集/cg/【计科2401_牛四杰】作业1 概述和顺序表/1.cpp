#include<bits/stdc++.h>
using namespace std;
void reverseArray(int arr[], int size)
{
    for(int i=0;i<size/2;i++)
    {
        swap(arr[i],arr[size-i-1]);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    reverseArray(arr,n);
    cout<<"{ ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"}";
    return 0;
}