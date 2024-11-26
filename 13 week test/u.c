#include<stdio.h>
#include<string.h>
void BubbleSort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++){
        int flag=0;
        for (j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if (flag==0){
            break;
        }
    }
}
int main()
{
    char a[10000];
    int b[10000],n,len;
    while(gets(a)){
        n=0;
        len=strlen(a);
        if(a[len-1]=='\n'){
            a[len-1]='\0';
            len--;
        }
        for(int i=0;i<len;i++){
            if('0'<=a[i]&&a[i]<='9'){
                b[n++]=a[i]-'0';
            }
        }
        BubbleSort(b,n);
        for(int i=0;i<n;i++){
            printf("%4d",b[i]);
        }
        printf("\n");
    }
    return 0;
}