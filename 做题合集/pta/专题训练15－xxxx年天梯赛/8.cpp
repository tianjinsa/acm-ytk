#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        map<int,int>mp;
        int id,h,m,nn=0;
        double sum=0;
        char c;
        while(scanf("%d %c %d:%d",&id,&c,&h,&m)!=EOF&&id){
            if(c=='S'){
                mp[id]=h*60+m;
            }else if(c=='E'&&mp.count(id)){
                sum+=h*60+m-mp[id];
                nn++;
                mp.erase(id);
            }
        }
        printf("%d %.0lf\n",nn,(nn==0?0:sum/nn));
    }

    return 0;
}