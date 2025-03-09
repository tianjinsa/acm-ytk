#include <bits/stdc++.h>
using namespace std;
int n,S,T;
vector<int>a;
bool check(double mid){
    vector<double>sum(n+1,0.0);
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+(a[i-1]-mid);
    }
    deque<int>dq;
    for(int j=S;j<=n;++j){
        int k=j-S;
        if(k>=0){
            while(!dq.empty()&&sum[dq.back()]>=sum[k]){
                dq.pop_back();
            }
            dq.push_back(k);
        }
        while(!dq.empty()&&dq.front()<j-T){
            dq.pop_front();
        }
        if(j>=S){
            if(!dq.empty()&&sum[j]-sum[dq.front()]>=0){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin>>n>>S>>T;
    a.resize(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    double l=*min_element(a.begin(),a.end());
    double r=*max_element(a.begin(),a.end());
    for(int i=0;i<36;++i){
        double mid=(l+r)/2;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    printf("%.3lf\n",l);
    return 0;
}
