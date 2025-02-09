#include<bits/stdc++.h>
using namespace std;
typedef struct point
{
    long long x, y, z;
}point;
int main()
{
    int N;
    cin>>N;
    unordered_map<int,point> a;
    for (int i=0;i<N;i++) {
        scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
    }
    long long ans=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(a[i].z > 282842 && a[j].z > 282842) continue;
            long long xx=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
            if(xx==a[i].z*a[i].z){
                ans++;
            }
            if(xx==a[j].z*a[j].z){
                ans++;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}