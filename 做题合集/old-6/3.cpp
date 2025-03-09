#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int h,m;
        scanf("%d:%d",&h,&m);
        m+=5;
        if(m>=60){
            m-=60;
            h++;
        }
        if(h>=24){
            h-=24;
        }
        printf("%02d:%02d\n",h,m);
    }   
    return 0;
}