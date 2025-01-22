#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    long long ans,max,min,minx,minx2,mm;
    ans=max=min=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            ans+=a[i]-max;
            max=a[i];
        }
        else if(a[i]<min){
            ans+=min-a[i];
            min=a[i];
            minx2=minx=i;
        }
    }
    to:
    a[minx]*=2;
    minx2=minx;
    min=max;
    if(a[minx]*2<max){
        for(int i=0;i<n;i++){
            if(a[i]<min){
                min=a[i];
                mm=i;
            }
        }
        if(mm>=minx&&minx2>=min||){
            printf("%d",max-min);
        }
        else{
            goto to;
        }
    }
    else{

    }
    
    printf("%lld",ans);
    return 0;
}