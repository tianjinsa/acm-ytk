#include<bits/stdc++.h>
//using namespace std;
int a[1000011];
void f()
{
    a[0]=7;
    a[1]=11;
    for(int i=2;i<1000011;i++){
        a[i]=(a[i-1]+a[i-2])%9;
    }
}
int main()
{
    int n;
    f();
    while(scanf("%d",&n)!=EOF){
        if(a[n]%3){
            printf("no\n");
        }
        else{
            printf("yes\n");
        }
    }
    return 0;
}