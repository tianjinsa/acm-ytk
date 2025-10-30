#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<bitset<1000>> aa(10001);
    for(int i=0;i<n;i++){
        int c;
        scanf("%d",&c);
        for(int j=0;j<c;j++){
            int t;
            scanf("%d",&t);
            aa[t].set(i);
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        auto t=aa[a]&aa[b];
        printf("%s",t.any()?"Yes\n":"No\n");
    }
    return 0;
}