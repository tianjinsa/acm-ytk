#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    int n;
    scanf("%d",&n);
    while(n--){
        cin>>a;
        if(a[a.length()-1]=='\n'){
            a[a.length()-1]=0;
        }
        if((a[a.length()-1]-'0')%2==0){
            printf("even\n");
        }else{
            printf("odd\n");
        }
    }
    return 0;
}