#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> v(N);
    for(int i=0;i<N;i++) cin >> v[i];
    for(int t=0;t<M;t++){
        int op;
        cin >> op;
        if(op == 1){
            int L1;
            cin >> L1;
            vector<int> a(L1);
            for(int i=0;i<L1;i++) cin >> a[i];
            int L2;
            cin >> L2;
            vector<int> b(L2);
            for(int i=0;i<L2;i++) cin >> b[i];
            int idx=-1;
            for(int i=0;i+L1 <=(int)v.size();i++){
                bool ok=true;
                for(int j=0;j<L1;j++){
                    if(v[i+j] != a[j]){ ok=false;break;}
                }
                if(ok){ idx=i;break;}
            }
            if(idx != -1){
                v.erase(v.begin()+idx,v.begin()+idx+L1);
                v.insert(v.begin()+idx,b.begin(),b.end());
            }
        }else if(op == 2){
            vector<int> nv;
            nv.reserve(v.size() * 2);
            for(int i=0;i <(int)v.size();i++){
                nv.push_back(v[i]);
                if(i+1 <(int)v.size() &&(v[i]+v[i+1]) % 2 == 0){
                    nv.push_back((v[i]+v[i+1]) / 2);
                }
            }
            v.swap(nv);
        }else{
            int l,r;
            cin >> l >> r;
            reverse(v.begin()+l - 1,v.begin()+r);
        }
    }
    for(int i=0;i <(int)v.size();i++){
        if(i) cout << ' ';
        cout << v[i];
    }
    return 0;
}