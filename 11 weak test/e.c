#include <stdio.h>
int main()
{
    int a,b,c,abc[26]={0};
    char ch;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=0;i<a;i++){
        getchar();
        for(int j=0;j<b;j++){
            scanf("%c",&ch);
            abc[ch-'A']++;
        }
        
    }
    getchar();
    while(c--){
        while(1){
            if(scanf("%c",&ch)==EOF||ch=='\n'){
                break;
            }
            abc[ch-'A']--;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        while (abc[i]--)
        {
            printf("%c",i+'A');
        }
        
    }
    
    return 0;
}