#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
    int n,t1,t2;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&t1,&t2);
        mp[t1]++;
        mp[t2]++;
    }
    int a[3]={0};
    t1=t2=0;
    for(auto i:mp){
        if(i.second>2){
            printf("-1");
            return 0;
        }
        if(i.second==1){
            if(t1==0){
                t1=i.first;
            }
            else if(t2==0){
                t2=i.first;
            }
            else{
                printf("-1");
                return 0;
            }
        }
        a[i.second]++;
    }
    printf("%d %d",t1,t2);
    return 0;
}