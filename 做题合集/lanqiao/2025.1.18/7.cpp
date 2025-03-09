#include<bits/stdc++.h>
//using namespace std;
bool sss(int n){
    char abc[10];
    sprintf(abc,"%d",n);
    if(strchr(abc,'2')!=NULL||strchr(abc,'0')!=NULL||strchr(abc,'1')!=NULL||strchr(abc,'9')!=NULL){
        return true;
    }
    return 0;
}
int main()
{
    long long n=0;
    for(int i=1;i<=2019;i++){
        if(sss(i)){
            n+=i*i;
        }
    }
    printf("%lld\n",n);
    return 0;
}