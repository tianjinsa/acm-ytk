#include<bits/stdc++.h>
//using namespace std;
void revstr(char s[])
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--){
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
char ch[111][111],x[111],t[111];
int main()
{
    int n,m,min,ll,minx;
    scanf("%d",&n);
    while(n--){
        min=111;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%s",ch[i]);
            ll=strlen(ch[i]);
            if(ll<min){
                min=ll;
                minx=i;
            }
        }
        for(int j=min;j>=0;j--){
            for(int k=0;k<=min-j;k++){
                strncpy(x,ch[minx]+k,j);
                x[j]='\0';
                strcpy(t,x);
                revstr(t);
                t[j]='\0';
                int ans=0;
                for(int q=0;q<m;q++){
                    if(strstr(ch[q],x)||strstr(ch[q],t)){
                        ans++;
                    }
                    else{
                        break;
                    }
                }
                if(ans==m){
                    printf("%d\n",j);
                    goto to;
                }
            }
        }
        to:;
    }
    return 0;
}