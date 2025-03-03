#include<stdio.h>
int sss(int n)
{
    int sum=0;
	while(n>0){
		sum=sum*10+n%10;
		n/=10;
	}
	return sum;
}
int prime(int n)
{
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}
int main()
{
    int n,nn=0;
    scanf("%d",&n);
    for(int i=11;i<=n;i+=2){
        if(prime(i)&&sss(i)==i){
            nn++;
        }
    }
    printf("%d",nn);
    return 0;
}