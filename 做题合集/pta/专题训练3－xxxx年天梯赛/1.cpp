#include<bits/stdc++.h>
using namespace std;

int main()
{
    string num;
    cin >> num;
    
    bool tt=0;
    if(num[0]=='-'){
        tt=true;
        num=num.erase(0,1);
    }
    int sum=0;
    for(char c:num){
        if(c=='2'){
            sum++;
        }
    }
    double out=1.0*sum/num.size();
    if(tt){
        out*=1.5;
    }
    if(((num[num.size()-1]-'0')%2==0)){
        out*=2;
    }
    printf("%.2f%%",out*100);
    
    return 0;
}