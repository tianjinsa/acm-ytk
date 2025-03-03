#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int main()
{
    char bbb[30],aaa[2][11];
    while(fgets(bbb,30,stdin)){
        if(bbb[0]=='\n'){
            break;
        }
        sscanf(bbb,"%s %s",aaa[0],aaa[1]);
        mp[aaa[1]]=aaa[0];
    }
    while(scanf("%s",bbb)!=EOF){
        if(mp.find(bbb)==mp.end()){
            printf("eh\n");
        }
        else{
            cout<<mp[bbb]<<endl;
        }
    }
    return 0;
}