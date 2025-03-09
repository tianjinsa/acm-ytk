#include<bits/stdc++.h>
using namespace std;
int M,N,L,T;
vector<vector<vector<char>>>a;
long long ss(int x,int y,int z){
    long long sum=0;
    a[x][y][z]=0;
    stack<tuple<int,int,int>>s;
    s.push({x,y,z});
    while(!s.empty()){
        auto [x,y,z]=s.top();
        s.pop();
        sum++;
        if(x-1>=0&&a[x-1][y][z]=='1'){
            s.push({x-1,y,z});
            a[x-1][y][z]=0;
        }
        if(x+1<L&&a[x+1][y][z]=='1'){
            s.push({x+1,y,z});
            a[x+1][y][z]=0;
        }
        if(y-1>=0&&a[x][y-1][z]=='1'){
            s.push({x,y-1,z});
            a[x][y-1][z]=0;
        }
        if(y+1<M&&a[x][y+1][z]=='1'){
            s.push({x,y+1,z});
            a[x][y+1][z]=0;
        }
        if(z-1>=0&&a[x][y][z-1]=='1'){
            s.push({x,y,z-1});
            a[x][y][z-1]=0;
        }
        if(z+1<N&&a[x][y][z+1]=='1'){
            s.push({x,y,z+1});
            a[x][y][z+1]=0;
        }
    }
    return sum;
}
int main()
{
    
    cin>>M>>N>>L>>T;
    a.resize(L,vector<vector<char>>(M,vector<char>(N)));
    for(int i=0;i<L;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<N;k++){
                scanf(" %c",&a[i][j][k]);
            }
        }
    }
    long long sum=0;
    for(int i=0;i<L;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<N;k++){
                if(a[i][j][k]=='1'){
                    long long tt;
                    sum+=((tt=ss(i,j,k))>=T?tt:0);
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}