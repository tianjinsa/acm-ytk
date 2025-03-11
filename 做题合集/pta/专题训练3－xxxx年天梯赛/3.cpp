#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,a=0,b=0;
    cin>>A>>B;
    int n;
    cin>>n;

    while(n--){
        int a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        a1+=b1;
        bool fl1,fl2;
        fl1=(a2!=a1);
        fl2=(b2!=a1);
        if(fl1!=fl2){
            if(fl1==0){
                a++;
            }
            else{
                b++;
            }
        }
        if((A-a)<0||(B-b)<0)break;
    }
    
    if((A-a)>=0)printf("B\n%d",a);
    else printf("A\n%d",b);

    return 0;
}