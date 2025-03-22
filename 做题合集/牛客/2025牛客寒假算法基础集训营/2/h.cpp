#include<bits/stdc++.h>
//using namespace std;
int main()
{
    long long n,x1,x2,y1,y2,a,b,c,d;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        
        
        if(b-a>d-c){
            x1=a,y1=d,x2=b,y2=d-1;
            printf("%lld %lld\n",x1,y1);
            printf("%lld %lld\n",x1+1,y1);
        }
        else{
            x1=b-1,y1=d,x2=b,y2=c;
            printf("%lld %lld\n",x1,y1);
            printf("%lld %lld\n",x2,y2+1);
        }
        printf("%lld %lld\n",x2,y2);
    }
    return 0;
}