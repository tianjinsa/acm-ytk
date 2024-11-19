#include<stdio.h>
int main()
{
    int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		n*=2;
		int fl=1;
		for(int i=2;i*i<=n;i++){
			if(n%i!=0){
                continue;
            }
			int x=(n/i-i+1)/2,y=x+i-1;
			if ((n/i-i+1)%2==0){
				printf("%d = %d",n/2,x);
				fl=0;
				for(int l=x+1; l<=y; l++){
                    printf(" + %d",l);
                }
				break;
			}
		}
		if(fl){
            printf("IMPOSSIBLE");
        }
		printf("\n");
	}
	return 0;
}