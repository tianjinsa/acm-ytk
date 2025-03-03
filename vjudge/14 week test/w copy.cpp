#include<bits/stdc++.h>
//using namespace std;
char xx[100000001][2][5];
int a,b,x1[40];
long long nt=40;
void f1()
{
    x1[0]=0;
    x1[1]=1;
    for(int i=2;i<40;i++){
        x1[i]=x1[i-1]+x1[i-2];
    }
}
void f2(int n)
{
    int abc[3][2];
    abc[0][0]=atoi(xx[nt-1][0]);
    abc[0][1]=atoi(xx[nt-1][1]);
    abc[1][0]=atoi(xx[nt][0]);
    abc[1][1]=atoi(xx[nt][1]);
    for(;nt<=n;){
        abc[2][0]=abc[1][0]+abc[0][0];
        if(abc[2][0]>=10000){
            abc[2][0]/=10;
        }
        abc[2][1]=(abc[1][1]+abc[0][1])%10000;
        sprintf(xx[++nt][0],"%d",abc[2][0]);
        sprintf(xx[nt][1],"%04d",abc[2][1]);
        abc[0][0]=abc[1][0];
        abc[1][0]=abc[2][0];
        abc[0][1]=abc[1][1];
        abc[1][1]=abc[2][1];
    }
}
int main()
{
    f1();
    strcpy(xx[39][0],"6324");
    strcpy(xx[39][1],"5986");
    strcpy(xx[40][0],"1023");
    strcpy(xx[40][1],"4155");
    long long nn;
    while(scanf("%lld",&nn)!=EOF){
        if(nn<=39){
            printf("%d\n",x1[nn]);
            continue;
        }
        if(nn>nt){
            f2(nn);
        }
        printf("%s...%s\n",xx[nn][0],xx[nn][1]);
    }
    return 0;
}