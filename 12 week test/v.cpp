#include<bits/stdc++.h>
using namespace std;
//#include<stdio.h>

//#include<math.h>
int main()
{
    long long a,b,sum;
    int n;
    scanf("%d",&n);
    while(n--){
        cin>>a;
        //scanf("%lld",&a);
        b=a;
        sum=sqrt((double)2*b);
        for(long long i=sum;i>1;i--){
            sum=(b-i*(i+1)/2)/i+1;
            if(sum*i+i*(i-1)/2==b){
                printf("%lld = %lld",a,sum);
                for(int j=sum+1;j<=sum+i-1;j++){
                    cout<<" + "<<j;
                    //printf(" + %d",j);
                }
                cout<<endl;
                //printf("\n");
                goto to;
            }
        }
        cout<<"IMPOSSIBLE"<<endl;
        //printf("IMPOSSIBLE\n");
        to:
    }
    return 0;
}