#include<bits/stdc++.h>
//using namespace std;
double x1[10000001];
char s[10000000];
void f1()
{
    x1[0]=0;
    x1[1]=1;
    for(int i=2;i<100000001;i++){
        x1[i]=x1[i-1]+x1[i-2];
    }
}
int main()
{
    int n;
    f1();
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=39){
            printf("%.0lf\n",x1[n]);
        }
        else{
            
            sprintf(s,"%.0lf",x1[n]);
            printf("%c%c%c%c...%c%c%c%c\n",s[0],s[1],s[2],s[3],s[strlen(s)-4],s[strlen(s)-3],s[strlen(s)-2],s[strlen(s)-1]);
        }
    }
    return 0;
}