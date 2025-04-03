#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int sum=0,n;
    scanf("%d",&n);
    for(int i=1;n;i++){
        for(int j=0;j<i&&n;j++){
            sum+=i;
            n--;
        }
    }
    printf("%d",sum);
    return 0;
}