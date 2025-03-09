#include<bits/stdc++.h>
//using namespace std;

int sum(long long x,int base){
    int sum=0;
    while(x>0){
        sum+=x%base;
        x/=base;
    }
    return sum;
}

bool isb(long long x,int base){
    return x%sum(x,base) == 0;
}

bool isa(long long x){
    return isb(x,2)&&isb(x,8)&&isb(x,10)&&isb(x,16);
}

int main()
{
    long long count=0,i=1;
    while(true){
        if(isa(i)){
            count++;
            
            if(count==2023){
                printf("%d",i);
                break;
            }
        }
        i++;
    }
    return 0;
}