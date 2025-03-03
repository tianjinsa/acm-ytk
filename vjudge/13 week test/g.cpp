#include<bits/stdc++.h>
int xy[100001]={0};

int main()
{
    int n;
    scanf("%d\n",&n);
    char a[50],abc[]="22233344455566677778889999";
    for(int i=0;i<n;i++){
        fgets(a,50,stdin);
        for(int j=0,k=0;j<strlen(a);j++){
            if('A'<=a[j]&&a[j]<='Z'){
                a[k++]=abc[a[j]-'A'];
            }
            else if('0'<=a[j]&&a[j]<='9'){
                a[k++]=a[j];
            }
        }
        a[7]='\0';
        xy[i]=atoi(a);
    }
    std::sort(xy,xy+n);
    int fl=1,abcd=0;
    for(int i=0;i<n;i++){
        if(xy[i]==xy[i+1]){
            abcd++;
        }
        else if(abcd>=1){
            fl=0;
            printf("%03d-%04d %d\n",xy[i]/10000,xy[i]%10000,abcd+1);
            abcd=0;
        }
    }
    if(fl){
        printf("No duplicates.");
    }
    return 0;
}