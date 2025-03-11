#include<bits/stdc++.h>
using namespace std;
long long sum=0;
bool ss(vector<vector<char>> a,int L,int N){
    for(int i=0;i<N;i++){
        int sum1=0,sum2=0;
        for(int j=0;j<N;j++){
            sum1+=a[i][j];
            sum2+=a[j][i];
        }
        if(sum1!=L||sum2!=L)return 0;
    }
    return 1;
}
void ooo(int L, int N,int aaa,vector<vector<char>> a){
    
    if(N==1){
        sum=1;
        return;
    }
    if(N==2){
        sum=L+1;
        return;
    }
    if(N==3){
        if(aaa==9){
            if(ss(a,L,N))
                sum++;
            return;
        }
        for(int i=0;i<=L;i++){
            a[aaa/3][aaa%3]=i;
            ooo(L,N,aaa+1,a);
        }
    }
    if(N==4){
        if(aaa==16){
            if(ss(a,L,N))
                sum++;
            return;
        }
        for(int i=0;i<=L;i++){
            a[aaa/4][aaa%4]=i;
            ooo(L,N,aaa+1,a);
        }
    }
    return;
}

int main() {
    int L, N;
    cin >> L >> N;
    vector<vector<char>>a(N,vector<char>(N,0));
    sum=0;
    ooo(L,N,0,a);
    cout<<sum;
    return 0;
}