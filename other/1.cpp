#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main()

{
    int n;
    scanf("%d",&n);
    while(n--){
        string s;
        int x,y;
        scanf("%d%d",&x,&y);
        if(y<0){
            y=-y;
        }
        s=to_string(x)+" "+to_string(y);
        if(mp.find(s)==mp.end()){
            mp[s]=1;
        }
    }
    printf("%lld\n",mp.size());
    return 0;
}