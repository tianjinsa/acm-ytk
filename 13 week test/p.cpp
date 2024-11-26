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
    memset(d,1,26);
    memset(c,1,26);
    for(int i=0;i<strlen(a);i++){
        c[a[i]-'A']++;
        d[b[i]-'A']++;
    }
    strcpy(a,d);
    strcat(a,d);
    strcat(a,d);
    if(strstr(a,c)){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}