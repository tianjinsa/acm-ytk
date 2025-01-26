#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp1;
map<string,bool>mp2;
map<string,bool>mp3;
int main()
{
    int n,y,m;
    scanf("%d%d%d",&n,&y,&m);
    char ch[5];
    sprintf(ch,"%02d",m);
    string aimt=to_string(y)+"-"+string(ch);
    for(int i=0;i<n;i++){
        string id,date,time;
        cin>>id>>date>>time;
        if(date.find(aimt)==string::npos){
            continue;
        }
        if(("07:00:00"<=time&&time<="09:00:00")||("18:00:00"<=time&&time<="20:00:00")){
            mp1[id]=true;
        }
        else if("11:00:00"<=time&&time<="13:00:00"){
            mp2[id]=true;
        }
        else if(("22:00:00"<=time&&time<="23:59:59")||("00:00:00"<=time&&time<="01:00:00")){
            mp3[id]=true;
        }
    }
    printf("%d %d %d\n",(int)mp1.size(),(int)mp2.size(),(int)mp3.size());
    return 0;
}