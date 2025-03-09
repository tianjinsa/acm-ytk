#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int max=0,a,a2;
    scanf("%d",&a);
    for(int i=1;i<n;i++){
        scanf("%d",&a2);
        if(max<abs(a2-a)){
            max=abs(a2-a);
        }
        a=a2;
    }
    printf("%d",max);
    return 0;
}