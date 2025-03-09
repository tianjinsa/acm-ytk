#include<bits/stdc++.h>
//using namespace std;

int main()
{
    char a[11]={0};
    scanf("%c-%[^-]-%[^-]-%c",&a[0],a+1,a+4,&a[9]);
    int sum=0;
    for(int i=0;i<9;i++){
        sum+=(a[i]-'0')*(i+1);
    }
    sum%=11;
    if(sum==a[9]-'0'||(sum==10&&a[9]=='X')){
        printf("Right");
    }else{
        a[9]=sum+'0';
        if(sum==10){
            a[9]='X';
        }
        printf("%c-%c%c%c-%c%c%c%c%c-%c",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
    }

    return 0;
}