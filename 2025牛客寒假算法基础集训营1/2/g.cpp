#include<bits/stdc++.h>

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        double n,m;
        scanf("%lf%lf",&n,&m);
        long long ans=1,val1=1,val2=m;
        ans=(int)(log(n)/log(m));//向下取整
        if(ans<=0){
            printf("1\n");
            continue;
        }
        val1=(long long)pow(m,ans);
        val2=val1*m;
        if(n-val1>val2-n&&val1<n){
            printf("%lld\n",ans+1);
        }
        else{
            printf("%lld\n",ans);
        }
    }
    return 0;
}