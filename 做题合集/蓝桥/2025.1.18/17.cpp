#include<bits/stdc++.h>
//using namespace std;

int main()
{
    char abc[300];
    while(fgets(abc,300,stdin)){
        if('a'<=abc[0]&&abc[0]<='z'){
            printf("%c",abc[0]-'a'+'A');
        }
        else{
            printf("%c",abc[0]);
        }
        for(int i=1;abc[i]!='\0';i++){
            if(abc[i-1]==' '&&abc[i]==' '){
                continue;
            }
            else if((('0'<=abc[i]&&abc[i]<='9')&&('a'<=abc[i-1]&&abc[i-1]<='z'))||(('0'<=abc[i-1]&&abc[i-1]<='9')&&('a'<=abc[i]&&abc[i]<='z'))){
                printf("_");
            }
            else if(abc[i-1]==' '&&('a'<=abc[i]&&abc[i]<='z')){
                printf("%c",abc[i]-'a'+'A');
                continue;
            }
            printf("%c",abc[i]);
        }
    }
    
    return 0;
}