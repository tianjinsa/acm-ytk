#include<bits/stdc++.h>
//using namespace std;
void sss(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}
int main()
{
    int a[10];
    
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    int min=a[0],max=a[0],minx=0,maxx=0;
    for(int i=1;i<10;i++){
        if(a[i]<min){
            min=a[i];
            minx=i;
        }
        if(a[i]>max){
            max=a[i];
            maxx=i;
        }
    }
    sss(a[maxx],a[minx]);
    for(int i=0;i<9;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[9]);
    return 0;
}