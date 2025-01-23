#include<bits/stdc++.h>
//using namespace std;
int main()
{
    int n,x1,x2,y1,y2,a,b,c,d;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        x1=a,y1=d,x2=b,y2=c;
        printf("%d %d\n%d %d\n",x1,y1,x2,y2);
        if(b-a<d-c){
            printf("%d %d\n",x1+1,y1);
        }
        else{
            printf("%d %d\n",x2,y2+1);
        }
    }
    return 0;
}