#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n][2],out[n]={0};
    int c[n]={0};
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i][0],&a[i][1]);
        for(int j=a[i][0];j<=a[i][1];j++){
            c[j]++;
        }
    }
    return 0;
}