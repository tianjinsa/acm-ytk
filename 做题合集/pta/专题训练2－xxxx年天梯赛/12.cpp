#include<bits/stdc++.h>
using namespace std;
long long ss(int L,int N){
    if(N==2){
        return L+1;
    }
    else if(N==3){
        long long ans=0;
        for(int a11=0;a11<=L;++a11){
            for(int a12=0;a12<=L-a11;++a12){
                int a13=L-a11-a12;
                for(int a21=0;a21<=L-a11;++a21){
                    int a31=L-a11-a21;
                    for(int a22=0;a22<=L;++a22){
                        int a23=L-a21-a22;
                        int a32=L-a12-a22;
                        int a33=a11+a12+a21+a22-L;
                        if(a23>=0&&a32>=0&&a33>=0&&a31+a32+a33==L&&a13+a23+a33==L){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
    else if(N==4){
        long long ans=0;
        for(int a11=0;a11<=L;++a11){
            for(int a12=0;a12<=L;++a12){
                for(int a13=0;a13<=L-a11-a12;++a13){
                    for(int a21=0;a21<=L;++a21){
                        for(int a22=0;a22<=L;++a22){
                            for(int a31=0;a31<=L-a11-a21;++a31){
                                int a23=L-a21-a22;
                                int a32=L-a31-(L-a12-a22);
                                if(a23<0||a32<0)continue;
                                int a33=L-a31-a32;
                                int a14=L-a11-a12-a13;
                                int a24=L-a21-a22-a23;
                                int a34=L-a31-a32-a33;
                                int a41=L-a11-a21-a31;
                                int a42=L-a12-a22-a32;
                                int a43=L-a13-a23-a33;
                                int a44=L-a14-a24-a34;
                                if(a33>=0&&a14>=0&&a24>=0&&a34>=0&&a41>=0&&a42>=0&&a43>=0&&a44>=0&&a41+a42+a43+a44==L){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    return 0;
}

int main(){
    int L, N;
    cin>>L>>N;
    cout<<ss(L,N)<<endl;
    
    return 0;
}
