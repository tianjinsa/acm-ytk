#include<iostream>
using namespace std;
 
int main(){
	for (int a=123,b,c; a<=329; a++){
		b=2*a,c=3*a;
		if ((a%10)*(a/10%10)*(a/100)*(b%10)*(b/10%10)*(b/100)*(c%10)*(c/10%10)*(c/100)==1*2*3*4*5*6*7*8*9)
		//把a,b,c的个位 十位 百位 分别求出来，它们乘积是否等于  1*2*3*4*5*6*7*8*9
			cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}