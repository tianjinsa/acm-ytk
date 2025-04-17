#include<bits/stdc++.h>
using namespace std;
vector<bool> a(24*60*60,0);
int main()
{
    int n;
    cin>>n;
    while(n--){
        int a1,a2,a3,b1,b2,b3;
        scanf("%d:%d:%d - %d:%d:%d",&a1,&a2,&a3,&b1,&b2,&b3);
        for(int i=a1*60*60+a2*60+a3;i<=b1*60*60+b2*60+b3;i++){
            if(i!=b1*60*60+b2*60+b3){
                a[i]=1;
            }
        }
    }
    bool fl=0;
    for(int i=0;i<=23;i++){
        for(int j=0;j<=59;j++){
            for(int k=0;k<=59;k++){
                if(fl&&a[i*60*60+j*60+k]==1){
                    fl=0;
                    printf("%02d:%02d:%02d\n",i,j,k);
                }
                else if(!fl&&a[i*60*60+j*60+k]==0){
                    fl=1;
                    
                    printf("%02d:%02d:%02d - ",i,j,k);
                }
            }
        }
    }
    if(fl){
        printf("%02d:%02d:%02d\n",23,59,59);
    }
    return 0;
}