#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int a[8]={0},t;
    for(int i=0;i<7;i++){
        scanf("%d",&t);
        a[t]++;
    }
    if((a[1]||a[2]||a[3]||a[5]||a[6])&&a[4]==0&&a[7]==0){
        printf("YES\n");
        return 0;
    }
    else{
        printf("NO\n");
    }
    return 0;
}