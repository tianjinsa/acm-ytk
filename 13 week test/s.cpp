#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int abc[26]={0},maxx=0;
    while(n--){
        maxx=0;
        memset(abc,0,sizeof(abc));
        char a[1010];
        scanf("%s",a);
        for(int i=0;i<strlen(a);i++){
            abc[a[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(abc[i]>abc[maxx]){
                maxx=i;
            }
        }
        printf("%c %d\n",maxx+'a',abc[maxx]);
    }
    return 0;
}