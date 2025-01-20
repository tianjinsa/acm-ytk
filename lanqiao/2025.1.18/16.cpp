#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a,at,an=1,max=0;
    scanf("%d",&at);
    for(int i=1;i<n;i++){
        scanf("%d",&a);
        if(a>at){
            an++;
        }
        else{
            if(max<an){
                max=an;
            }
            an=1;
        }
        at=a;
    }
    if(max<an){
        max=an;
    }
    printf("%d",max);
    return 0;
}