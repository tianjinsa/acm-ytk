#include<bits/stdc++.h>
using namespace std;
class SQ1{
    int a[20];
    int n;
public:
    SQ1(int arr[],int size):n(size){
        for(int i=0;i<n;++i) a[i]=arr[i];
    }
    void ss(int m){
        if(n==0||m==0) return;
        reverse(a,a+n);
        reverse(a,a+(n-m));
        reverse(a+(n-m),a+n);
    }
    void print()const{
        cout<<"{ ";
        for(int i=0;i<n;++i) cout<<a[i]<<" ";
        cout<<"}";
    }
};
int main(){
    int n;
    cin>>n;
    int a[20];
    for(int i=0;i<n;++i) cin>>a[i];
    int m;
    cin>>m;
    SQ1 s(a,n);
    s.ss(m);
    s.print();
    return 0;
}