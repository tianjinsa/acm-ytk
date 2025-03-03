#include<bits/stdc++.h>
//using namespace std;

int main()
{
    long long n,nn;
    scanf("%lld",&n);
    while(n--){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        long long i;
        if(a==1){
            i=15;
            b--;
            while(b){
                i+=15;
                if(i%15==0&&i%150){
                    b--;
                }
            }
            printf("%lld\n",i);
            continue;
        }
        if(a==2){
            i=150;
            b--;
            while(b){
                i+=150;
                if(i%150==0&&i%750){
                    b--;
                }
            }
            printf("%lld\n",i);
            continue;
        }
        nn=i=75*(long long)pow(10,a-2);
        b--;
        while(b){
            i+=nn;
            if(i%nn==0&&i%(nn*10)){
                b--;
            }
        }
        printf("%lld\n",i);
    }
    return 0;
}