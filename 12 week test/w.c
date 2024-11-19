#include<stdio.h>
#include<stdlib.h>
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
    int n,a[20000];
    long long xx=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%*d %d",&a[i]);
    }
    BubbleSort(a,n);
    for(int i=0;i<n;i++){
        xx+=abs(a[i]-a[n/2]);
    }
    printf("%lld",xx);
    return 0;
}