#include <bits/stdc++.h>
void sw(char &a, char &b){
    char t=a;
    a=b;
    b=t;
}
int main(){
    char a[201],b[201];
    int n1,n2,t;
    scanf("%d%d",&n1,&n2);
    scanf("%s%s",a,b);
    scanf("%d",&t);
    for(int i=0;i<n1/2;i++){
        sw(a[i],a[n1-i-1]);
    }
    strcat(a,b);
    memset(b,0,sizeof(b));
    for(int i=0;i<n1;i++){
        b[i]=1;
    }
    for(int i=n1;i<n1+n2;i++){
        b[i]=2;
    }
    while(t--){
        for(int i=0;i<n1+n2-1;i++){
            if(b[i]==1&&b[i+1]==2){
                sw(a[i],a[i+1]);
                sw(b[i],b[i+1]);
                i++;
            }
        }
    }
    printf("%s\n",a);
    return 0;
}