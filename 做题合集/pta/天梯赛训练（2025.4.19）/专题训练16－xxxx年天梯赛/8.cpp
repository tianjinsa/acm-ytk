#include<bits/stdc++.h>
using namespace std;
bool is(char c){
    if(isalpha(c)||isdigit(c)) return 1;
    return 0;
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin.ignore(1,'\n');
    while(n--){
        vector<string>lis;
        getline(cin, s);
        cout<<s<<endl;
        stringstream ss(s);
        string word;
        while(ss>>word){
            
            for(auto &c:word){
                if(c!='I')
                c=tolower(c);
            }
            int t;
            bool fff=0;
            while((t=word.find('?'))!=-1){
                word.replace(t,1,"!");
            }
            if((t=word.find('I'))!=-1&&(t==0||!is(word[t-1]))&&(t==word.size()-1||!is(word[t+1]))){
                word.replace(t,1,"you");
                fff=1;
            }
            else if((t=word.find("me"))!=-1&&(t==0||!is(word[t-1]))&&(t==word.size()-2||!is(word[t+2]))){
                word.replace(t,2,"you");
                fff=1;
            }
            string a,b;
            if((t=word.find_first_not_of("abcdefghijklmnopqrstuvwxyzI0123456789"))!=-1){
                if(t!=0)
                    a=word.substr(0,t);
                b=word.substr(t);
            }
            else{
                a=word;
            }
            if(!fff&&a=="you"){
                if((t=lis[lis.size()-1].rfind("can"))!=-1&&t==lis[lis.size()-1].size()-3){
                    lis[lis.size()-1]="I";
                    a="can";
                }
                else if((t=lis[lis.size()-1].rfind("could"))!=-1&&t==lis[lis.size()-1].size()-5){
                    lis[lis.size()-1]="I";
                    a="could";
                }
            }
            if(a!="")
                lis.push_back(a);
            if(b!="")
                lis.push_back(b);
        }
        bool fl=0;
        cout<<"AI: ";
        for(auto sss:lis){
            if(fl&&is(sss[0]))cout<<' ';
            fl=1;
            cout<<sss;
        }
        cout<<endl;
    }
    return 0;
}