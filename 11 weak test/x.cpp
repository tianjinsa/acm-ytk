#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,abc[1080];
    scanf("%d", &n);
	while(n--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d",&abc[i]);
        }
        while(k--){
            next_permutation(abc,abc+n);
        }
        for(int i=0;i<n-1;i++){
            printf("%d ",abc[i]);
        }
		printf("%d\n",abc[n-1]);
    }
    return 0;
}