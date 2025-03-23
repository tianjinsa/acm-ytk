#include<bits/stdc++.h>
using namespace std;
set<pair<string,string>> a;
int main()
{
    int n;
    cin>>n;
    while(n--){
        string as,bs;
        char t1[100],t2[100];
        scanf("%s - %s",t1,t2);
        as=t1;
        bs=t2;
        a.insert({as,bs});
    }
    auto i=a.begin(),j=next(i);
    if(i->first!="00:00:00"){
        cout<<"00:00:00"<<" - "<<i->first<<endl;
    }

    for(j=next(i);j!=a.end();i++,j++){
        if(i->second!=j->first)
        cout<<i->second<<" - "<<j->first<<endl;
    }
    if(i->second!="23:59:59"){
        cout<<i->second<<" - "<<"23:59:59";
    }
    return 0;
}