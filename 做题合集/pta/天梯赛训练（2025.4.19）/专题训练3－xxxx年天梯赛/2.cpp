#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h,m;
    scanf("%d:%d",&h,&m);
    if(h<12||(h == 12 && m == 0)){
        printf("Only %02d:%02d.  Too early to Dang.",h,m);
    }
    else{
        int ans;
        if(m==0){
            ans=h-12;
        }
        else{
            ans=h+1-12;
        }
        for(int i=0;i<ans;i++){
            printf("Dang");
        }
    }
    
    return 0;
}