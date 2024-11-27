#include<bits/stdc++.h>
//using namespace std;
void strrev(char s[])
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--){
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
char ch[101][101],abc[101*101],temp[101*101],x[101];
int sss(char x[])
{
    int n=0;
    char *p;
    strcpy(temp,abc);
    while((p=strstr(temp,x))||(strrev(x),p=strstr(temp,x))){
        n++;
        memset(temp+(p-temp)/21*21,1,21);
    }
    return n;
}
int main()
{
    int n,m,min=200,num[101];
    scanf("%d",&n);
    while(n--){
        memset(abc,1,sizeof(abc));
        abc[101*101-1]='\0';
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%s",ch[i]);
            for(int j=0;ch[i][j]!='\0';j++){
                abc[i*101+j]=ch[i][j];
            }
            num[i]=strlen(ch[i]);
            if(num[i]<min){
                min=num[i];
            }
        }
        for(int i=0;i<m;i++){
            if(num[i]==min){
                for(int j=strlen(ch[i]);j>=1;j--){
                    for(int k=0;k<=strlen(ch[i])-j;k++){
                        strncpy(x,ch[i]+k,j);
                        x[j]='\0';
                        if(sss(x)==m){
                            printf("%lld\n",strlen(x));
                            goto to;
                        }
                    }
                }
            }
        }
        to:;
    }
    return 0;
}