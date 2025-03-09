#include<bits/stdc++.h>
//using namespace std;
int xx[1001];
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        for(int i=0;i<a;i++){
            xx[i]=i+1;
        }
        for(int i=0;i<b-1;i++){
            std::next_permutation(xx,xx+a);
        }
        for(int i=0;i<a-1;i++){
            printf("%d ",xx[i]);
        }
        printf("%d\n",xx[a-1]);
    }
    return 0;
}