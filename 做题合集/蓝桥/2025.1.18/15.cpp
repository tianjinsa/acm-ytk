#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int max=0,n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<i;j++){
            if(max<abs(i-j)+abs(a[i]-a[j])){
                max=abs(i-j)+abs(a[i]-a[j]);
            }
        }
    }
    printf("%d",max);
    return 0;
}