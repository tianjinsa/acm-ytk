#include<bits/stdc++.h>
//using namespace std;

int main()
{
    char a;
    int flag=0;
    while(scanf("%c",&a)!=EOF){
        if(a=='"'){
            if(flag==0){
                printf("``");
                flag=1;
            }
            else{
                printf("''");
                flag=0;
            }
        }
        else{
            printf("%c",a);
        }
    }
    return 0;
}