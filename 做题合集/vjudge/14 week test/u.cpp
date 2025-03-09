#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n,m;
    scanf("%d",&n);
    while(n--){
        long long abc[55][26]={0};
        char a[33],b[33];
        scanf("%s%s%d",a,b,&m);
        for(int i=0;i<strlen(a);i++){
            abc[0][a[i]-'a']+=1;
        }
        for(int j=0;j<strlen(b);j++){
            abc[1][b[j]-'a']+=1;
        }
        for(int i=2;i<=m;i++){
            for(int j=0;j<26;j++){
                abc[i][j]=abc[i-1][j]+abc[i-2][j];
            }
        }
        for(int i=0;i<26;i++){
            printf("%c:%lld\n",i+'a',abc[m][i]);
        }
        printf("\n");
    }
    return 0;
}