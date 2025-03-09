#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    printf("Yes\n");
    int nn=1;
    printf("1 ");
    for(int i=2;i<n+2;i++){
        nn+=i;
        printf("%d ",nn);
    }
    int floor=n+1;
    while(floor--){
        for(int i=0;i<floor;i++){
            nn--;
            printf("%d ",nn);
        }
        printf("%d ",nn-=floor);
        if(nn==1)break;
        for(int i=0;i<floor-1;i++){
            nn+=floor+1;
            printf("%d ",nn);
            nn-=floor;
            printf("%d ",nn);
        }
    }
    
    return 0;
}