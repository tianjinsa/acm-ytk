#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    const double PI=acos(-1);
    while(T--){
        double A,B,C,x,y,z,r;
        cin>>A>>B>>C>>x>>y>>z>>r;
        // direction vector
        double ux=A,uy=B,uz=C;
        double norm=sqrt(ux*ux+uy*uy+uz*uz);
        ux/=norm;uy/=norm;uz/=norm;
        double theta=r*PI/180;
        // Rodrigues for +theta and -theta
        auto rot=[&](double ang){
            double c=cos(ang),s=sin(ang);
            double dot=x*ux+y*uy+z*uz;
            double rx=ux*dot*(1-c)+x*c+(-z*uy+y*uz)*s;
            double ry=uy*dot*(1-c)+y*c+( z*ux-x*uz)*s;
            double rz=uz*dot*(1-c)+z*c+(-y*ux+x*uy)*s;
            return array<double,3>{rx,ry,rz};
        };
        auto P=rot(theta);
        auto Q=rot(-theta);
        double rx,ry,rz;
        if(P[2]>Q[2]) rx=P[0],ry=P[1],rz=P[2];
        else rx=Q[0],ry=Q[1],rz=Q[2];
        cout<<fixed<<setprecision(9)<<rx<<" "<<ry<<" "<<rz<<"\n";
    }
    return 0;
}