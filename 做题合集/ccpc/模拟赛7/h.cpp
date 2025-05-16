#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t,n;
    cin>>t>>n;

    while(t--){
        long long k,kk;
        cin>>k;
        kk=k;
        string s;
        if(k%2){
            //cout<<-1<<endl;
            continue;
        }
        long long x=n,y=n;
        while(k-2>=0&&x-1){
            k-=2;
            x--;
            s='R'+s;
        }
        while(y!=1){
            while(k%2==1){
                s="RDLU"+s;
                k--;
            }
            while(k%2==0&&y!=1){
                s='D'+s;
                k/=2;
                y--;
            }
            
        }
        long long aa=0,x1=1,y1=min(n,(x-1)/(kk)+4);
        string ss="DRUL"+string(y1-1,'D');
        if(x==1){
            while(k>1){
                s="RDLU"+s;
                k--;
            }
            if(k)
            cout<<s<<endl;
            else{
                cout<<"DRUL"+s<<endl;
            }
        }
        else{
            while(x1!=x){
                aa+=2;
                ss+='R';
                x1++;
                if(aa+2>=2*kk&&x1!=x){
                    if(y1!=1){
                        
                        if(aa%2){
                            aa-=1;
                            ss+="DRUL";
                        }
                        ss+="U";
                        aa/=2;
                        y1--;
                    }
                    else{
                        ss+="DRULDRUL";
                        aa-=2;
                    }
                }
            }
            
            while(y1!=y){
                while(aa%2==1){
                    ss+="RDLU";
                    aa++;
                }
                while(aa%2==0&&y1!=1){
                    ss+='U';
                    aa/=2;
                    y1--;
                }
            }
            while(aa>k){
                ss+="DRUL";
                aa--;
            }
            while(aa<k){
                ss+="RDLU";
                aa++;
            }
            ss+=s;
            cout<<ss<<endl;
        }

    }

    return 0;
}