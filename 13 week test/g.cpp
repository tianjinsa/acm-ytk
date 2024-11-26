#include<bits/stdc++.h>

void BubbleSort(char arr[][50],int n,int a[])
{
    int i,j;
    char temp[50];
    for(i=0;i<n-1;i++){
        int fl=0;
        if(a[i]<=0){
            continue;
        }
        for(j=0;j<n-i-1;j++){
            if(a[j]>0&&strcmp(arr[j],arr[j+1])>0){
                strcpy(temp,arr[j]);
                strcpy(arr[j],arr[j+1]);
                strcpy(arr[j+1],temp);
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                fl=1;
            }
        }
        if(fl==0){
            break;
        }
    }
}
int main()
{
    int n;
    scanf("%d\n",&n);
    char a[n][50],xx;
    int flag[n]={0};
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
        int k=0;
        while(scanf("%c",&xx)!=EOF){
            if(xx=='\n'){
                xx='\0';
                break;
            }
            else if(xx!='-'){
                if(xx>='A'&&xx<='C'){
                    a[i][k++]='2';
                }
                else if(xx>='D'&&xx<='F'){
                    a[i][k++]='3';
                }
                else if(xx>='G'&&xx<='I'){
                    a[i][k++]='4';
                }
                else if(xx>='J'&&xx<='L'){
                    a[i][k++]='5';
                }
                else if(xx>='M'&&xx<='O'){
                    a[i][k++]='6';
                }
                else if(xx>='P'&&xx<='S'){
                    a[i][k++]='7';
                }
                else if(xx>='T'&&xx<='V'){
                    a[i][k++]='8';
                }
                else if(xx>='W'&&xx<='Y'){
                    a[i][k++]='9';
                }
                else{
                    a[i][k++]=xx;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(flag[i]==0){
            for(int j=i+1;j<n;j++){
                if(flag[j]==0&&strcmp(a[i],a[j])==0){
                    flag[i]+=1;
                    flag[j]=-1;
                }
            }
        }
    }
    BubbleSort(a,n,flag);
    int c=0;
    for(int i=0;i<n;i++){
        if(flag[i]>=1){
            c=1;
            for(int j=0;j<strlen(a[i]);j++){
                printf("%c",a[i][j]);
                if(j==2){
                    printf("-");
                }
            }
            printf(" %d\n",flag[i]+1);
        }
    }
    if(c==0){
        printf("No duplicates.");
    }
    return 0;
}