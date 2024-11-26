#include<bits/stdc++.h>
char abc[10][100000][2][11];
int main()
{
    char aaa[2][11],bbb[30];
    int a[10]={0};
    while(fgets(bbb,30,stdin)){
        if(bbb[0]=='\n'){
            break;
        }
        sscanf(bbb,"%s %s",aaa[0],aaa[1]);
        strcpy(abc[strlen(aaa[1])][a[strlen(aaa[1])]++][0],aaa[0]);
        strcpy(abc[strlen(aaa[1])][a[strlen(aaa[1])]-1][1],aaa[1]);
    }
    while(scanf("%s",bbb)!=EOF){
        bool flag=0;
        for(int i=0;i<a[strlen(bbb)];i++){
            if(strcmp(abc[strlen(bbb)][i][1],bbb)==0){
                printf("%s\n",abc[strlen(bbb)][i][0]);
                flag=1;
                break;
            }
        }
        if(!flag){
            printf("eh\n");
        }
    }
    return 0;
}