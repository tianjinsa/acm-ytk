#include<bits/stdc++.h>
using namespace std;
long long cpls(int n,int k)//(下标，上标)
{
    if(k>n-k)k=n-k;
    long long xx=1;
    for(int i=0;i<k;i++){
        xx*=(n-i);
        xx/=(i+1);
    }
    return xx;
}
int main()
{
    string s;
    getline(cin,s);
    vector<pair<char,int>>all;
    all.push_back({s[0],1});
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            all.back().second++;
        }
        else{
            all.push_back({s[i],1});
        }
    }
    long long sum=1+all.size()+cpls(s.size(),2)+cpls(s.size(),3);
    for(int i=0;i<all.size();i++){
        if(all[i].second>=2){
            sum-=cpls(all[i].second,1);
            sum-=cpls(all[i].second,2);
        }
    }
    for(auto &block : all){
        int len = block.second;
        
        if(len > 1){ 
            sum -= cpls(len, 1) - 1;
        }
        
        if(len > 2){
            sum -= cpls(len, 2) - 1;
        }
        
        if(len > 3){
            sum -= cpls(len, 3) - 1;
        }
    }
    
    for(int i = 0; i < all.size(); i++){
        for(int j = i+1; j < all.size(); j++){
            int len_i = all[i].second;
            int len_j = all[j].second;
            
            if(len_i > 1 && len_j > 1){
                sum -= (cpls(len_i, 1) - 1) * (cpls(len_j, 1) - 1);
            }
            
            if(len_i > 2 && len_j > 1){
                sum -= (cpls(len_i, 2) - 1) * (cpls(len_j, 1) - 1);
            }
            
            if(len_i > 1 && len_j > 2){
                sum -= (cpls(len_i, 1) - 1) * (cpls(len_j, 2) - 1);
            }
        }
    }
    
    for(int i = 0; i < all.size(); i++){
        for(int j = i+1; j < all.size(); j++){
            for(int k = j+1; k < all.size(); k++){
                int len_i = all[i].second;
                int len_j = all[j].second;
                int len_k = all[k].second;
                
                if(len_i > 1 && len_j > 1 && len_k > 1){
                    sum -= (cpls(len_i, 1) - 1) * (cpls(len_j, 1) - 1) * (cpls(len_k, 1) - 1);
                }
            }
        }
    }
    
    cout<<sum<<endl;
    return 0;
}