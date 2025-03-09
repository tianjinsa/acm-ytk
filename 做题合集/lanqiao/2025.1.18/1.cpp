#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int a,min,max,sum,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(i==0){
            min=a;
            max=a;
            sum=a;
        }
        else{
            if(a<min){
                min=a;
            }
            if(a>max){
                max=a;
            }
            sum+=a;
        }
    }
    printf("%d\n%d\n%.2lf\n",max,min,1.0*sum/n);
    return 0;
}