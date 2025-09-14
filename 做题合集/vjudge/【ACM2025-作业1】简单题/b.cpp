#include<iostream>
using namespace std;

int main()
{
    double a,sum=0;
    for(int i=0;i<12;i++){
        cin>>a;
        sum+=a;
    }
    printf("$%.2f\n",sum/12);
    return 0;
}