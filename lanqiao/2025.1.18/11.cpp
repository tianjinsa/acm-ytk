#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int year;
    scanf("%d",&year);
    char abc[2][12][6]={{"jia","yi","bing","ding","wu","ji","geng","xin","ren","gui"},{"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"}};
    printf("%s%s",abc[0][(year-4)%10],abc[1][(year-4)%12]);
    return 0;
}