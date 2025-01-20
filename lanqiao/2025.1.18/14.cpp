#include<bits/stdc++.h>
//using namespace std;
bool isLeap(int y){
    return (y%4==0&&y%100!=0)||y%400==0;
}
int sum(int n){
    int sum=0;
    while(n>0) {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},y=1900,m=1,d=1,nn=0;

    for(;y<10000;d++){
        
        if(d>month[m]+(isLeap(y)&&m==2)){
            d=1;
            m++;
        }
        if(m>12){
            m=1;
            y++;
        }
        if(sum(y)==sum(m)+sum(d)){
            nn++;
        }
        
    }
    printf("%d\n",nn);
    return 0;
}