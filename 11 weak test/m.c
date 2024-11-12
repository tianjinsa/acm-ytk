#include <stdio.h>
#include <string.h>
int main()
{
    int n,nn,b,c,d,e;
    char ach[200];
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        b=c=d=e=0;
        
        fgets(ach,200,stdin);
        nn=strlen(ach);
        if(ach[nn-1]=='\n'){
            ach[nn-1]='\0';
            nn--;
        }
        if(nn<8||16<nn){
            printf("NO\n");
            continue;
        }
        for(int j=0;j<nn;j++){
            if(ach[j]>='a'&&ach[j]<='z'){
                b=1;
            }
            else if(ach[j]>='A'&&ach[j]<='Z'){
                c=1;
            }
            else if(ach[j]>='0'&&ach[j]<='9'){
                d=1;
            }
            else if(ach[j]=='~'||ach[j]=='!'||ach[j]=='@'||ach[j]=='#'||ach[j]=='$'||ach[j]=='%'||ach[j]=='^'){
                e=1;
            }
            if(b+c+d+e>=3){
                break;
            }
        }
        if(b+c+d+e>=3){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    
    return 0;
}