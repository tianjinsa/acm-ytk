#include<bits/stdc++.h>
//using namespace std;
char abc[21*2001],ch[2001][21],x[21];
int sss(char x[])
{
    int n=0;
    char *p;
    char temp[21*2001];
    strcpy(temp,abc);
    while(p=strstr(temp,x)){
        n++;
        if((p-temp)%21){
            n--;
        }
        memset(temp+(p-temp)/21*21,1,21);
    }
    return n;
}
int main()
{
    int n=0;
    char a;
    memset(abc,1,sizeof(abc));
    while(scanf("%s",ch[n])!=EOF){
        for(int i=0;ch[n][i]!='\0';i++){
            abc[n*21+i]=ch[n][i];
        }
        n++;
    }
    bool fl=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<strlen(ch[i]);j++){
            for(int k=0;k<j;k++){
                x[k]=ch[i][k];
            }
            x[j]='\0';
            if(sss(x)==1){
                printf("%s %s\n",ch[i],x);
                fl=0;
                break;
            }
        }
        if(fl){
            printf("%s %s\n",ch[i],ch[i]);
        }
    }
    return 0;
}