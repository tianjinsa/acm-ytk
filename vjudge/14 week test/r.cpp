#include<bits/stdc++.h>
//using namespace std;/
int aa[51];
bool ff(int n)
{
    if(pow((int)sqrt(n),2)==n)
        return 1;
    return 0;
}
int main()
{
    int t,n;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        int xx[t]={0},i;
        if(aa[t]==0){
            for(i=1;;i++){
                for(int j=0;j<t;j++){
                    if(xx[j]==0||ff(xx[j]+i)){
                        xx[j]=i;
                        break;
                    }
                    else if(j==t-1){
                        goto to;
                    }
                }
            }
            to:
        }
        aa[t]=i-1;
        printf("%d\n",aa[t]);
    }
    return 0;
}