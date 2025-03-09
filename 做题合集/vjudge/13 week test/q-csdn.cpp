#include<iostream>
#include<map>
using namespace std;
map<string,string>mp;
 
 
int main()
{
	char a[30],b[15],c[15];
	while(gets(a) && a[0] != '\0')//不是空串的时候读入 
	{
		sscanf(a,"%s%s",b,c);
		mp[c]=b;
	}
	map<string,string>::iterator p;
	while(gets(a))
	{
		p = mp.find(a);
		if(p == mp.end())
			printf("%s\n","eh");
		else
			cout << mp[a] << endl;
	}
	return 0;
} 