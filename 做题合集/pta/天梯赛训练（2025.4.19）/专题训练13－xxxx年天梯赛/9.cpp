#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    while(k--){
        int t,cc=1;
        stack<int>st;
        bool fl=1;
        for(int i=1;i<=n;i++){
            cin>>t;
            if(!fl)continue;
            if(t!=cc){
                if(!st.empty()&&st.top()==cc){
                    st.pop();
                    cc++;
                    st.push(t);
                }
                else{
                    if(st.size()==m){
                        fl=0;
                        continue;
                    }
                    st.push(t);
                }
            }
            else{
                cc++;
                while(!st.empty() && st.top() == cc) {
                    st.pop();
                    cc++;
                }
            }
        }
        while(!st.empty()&&fl){
            if(st.top()!=cc++){       
                fl=0;
                break;
            }
            st.pop();
        }
        if(fl){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}