#include<bits/stdc++.h>
int main()
{
    char a[200],b[200],c[200]={0},d[200]={0};
    gets(a);
    gets(b);
    if(a[strlen(a)-1]=='\n'){
        a[strlen(a)-1]='\0';
    }
    if(b[strlen(b)-1]=='\n'){
        b[strlen(b)-1]='\0';
    }
    if(strlen(a)!=strlen(b)){
        printf("NO");
        return 0;
    }
    memset(d,0,26);
    memset(c,0,26);
    for(int i=0;i<strlen(a);i++){
        c[a[i]-'A']++;
        d[b[i]-'A']++;
    }
    int mm=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<26&&c[i];j++){
            if(c[i]==d[j]){
                c[i]=0;
                d[j]=0;
            }
        }
    }
    for(int i=0;i<26;i++){
        if(c[i]>0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}