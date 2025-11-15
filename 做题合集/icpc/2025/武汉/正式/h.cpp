#include <bits/stdc++.h>
using namespace std;
using uint=uint32_t;
unordered_set<uint> a;
vector<vector<uint>> g(32,vector<uint>(32));
inline int bit(uint v,uint k)
{
    uint t=1<<k;
    for(;t;k--,t>>=1) if(v&t)return k;
    return -1;
}
inline uint outin(uint x)
{
    // printf("? %u\n", x);
    //二进制输出
    cout<<bitset<32>(x)<<endl;
    // scanf(" %u", &x);
    //二进制输入
    bitset<32> bs;
    cin>>bs;
    uint y=bs.to_ulong();
    y^=x;
    cout<<bitset<32>(y)<<" -Received"<<endl;
    // a.insert(y);
    return y;
}
void dfs(uint maxx,uint minn)
{
    a.insert(minn);
    a.insert(maxx);
    uint l=__bit_width(maxx^minn)-1,r;
    r=bit(minn,l);
    cout<<"DFS l:"<<l<<" r:"<<r<<" maxx:"<<bitset<32>(maxx)<<" minn:"<<bitset<32>(minn)<<endl;
    uint v,t=(maxx^g[l+1][31])&g[l+1][31];
    // cout<<"  Going up with t:"<<bitset<32>(t)<<endl;
    for(int i=l;i>r;i--){
        cout<<"  i:"<<i<<endl;
        v=outin(t|g[i][l]);
        if(v<=minn||v>=maxx||a.insert(v).second==0) break;
        dfs(maxx,outin((maxx^g[i][31])|g[0][i-1]));
        i=bit(v,i)+1;
        maxx=v;

    }
}

int main()
{
    g[0][0]=1;
    for(uint i=0;i<32;i++){
        uint t=1<<i;
        for(uint j=i;j<32;j++){
            if(j==i){
                if(i){
                    g[i][j]=g[i-1][j-1]<<1;
            // cout<<"g["<<i<<"]["<<j<<"] \t="<<bitset<32>(g[i][j])<<endl;

                    g[j][i]=g[i][j];
                }
                continue;
            }
            g[i][j]=(g[i][j-1]<<1)|t;
            // cout<<"g["<<i<<"]["<<j<<"] \t="<<bitset<32>(g[i][j])<<endl;
            g[j][i]=g[i][j];
        }
    }

    uint T;
    scanf(" %u", &T);
    while (T--)
    {
        uint n;
        scanf(" %u", &n);
        a.clear();
        dfs(outin(0),outin(UINT32_MAX));
        printf("!");
        for(const uint &x:a) printf(" %u",x);
        printf("\n");
    }

    return 0;
}