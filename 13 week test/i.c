#include<stdio.h>
#include<string.h>
int main()
{
    int n,a[10001]={0},max=0;
    char ch[10001][51];
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        gets(ch[i]);
        for(int j=0;ch[i][j]!='.';j++){
            a[i]=j+1;
        }
        if(a[i]>max){
            max=a[i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<max-a[i];j++){
            printf(" ");
        }
        printf("%s\n",ch[i]);
    }
    return 0;
}