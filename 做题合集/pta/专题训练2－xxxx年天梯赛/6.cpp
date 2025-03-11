#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n]={0};
    double b[n],sum=0;
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    int i,j;
    while(cin>>i>>j&&i){
        a[i-1]+=j;
        sum+=b[i-1]*j;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    printf("%.2lf",sum);
    return 0;
}