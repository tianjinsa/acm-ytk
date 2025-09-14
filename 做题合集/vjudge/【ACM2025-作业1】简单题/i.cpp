#include<bits/stdc++.h>
using namespace std;
long double PI=acos(-1);
using ld=long double;
ld r,c;
struct node{
    bool fl;
    ld x1,y1,x2,y2,ox,oy;
    bool arc0to90;
};
struct Point { ld x,y; };
static inline bool eq(ld a, ld b) {
    return fabsl(a - b) < 1e-9L;
}
ld dist(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
// 计算圆弧与线段的交点并返回交点及连线与x轴的弧度
tuple<ld,ld,ld> intersectArcSegment(ld cx,ld cy,ld x1,ld y1,ld x2,ld y2,bool arc0to90)
{
    Point pt;
    if (eq(y1, y2)) {
        ld y=y1;
        ld d=r*r-(y-cy)*(y-cy);
        pt={cx + (arc0to90 ? sqrt(d) : -sqrt(d)),y};
    } else {
        ld x=x1;
        ld d=r*r-(x-cx)*(x-cx);
        pt={x,cy + sqrt(d)};
    }
    ld ang=atan2(pt.y-cy,pt.x-cx);
    return {pt.x,pt.y,ang};
}

// 计算两个固定圆弧(第一弧90~0,第二弧180~90)的交点并返回交点及两弧对应连线与x轴弧度
tuple<ld,ld,ld,ld> intersectArcArc(ld cx1,ld cy1,ld cx2,ld cy2)
{
    ld dx=cx2-cx1,dy=cy2-cy1;
    ld d=sqrt(dx*dx+dy*dy);
    ld mx=(cx1+cx2)/2,my=(cy1+cy2)/2;
    ld h=sqrt(r*r-(d/2)*(d/2));
    ld rx=-dy*(h/d),ry=dx*(h/d);
    Point p1={mx+rx,my+ry};
    Point p2={mx-rx,my-ry};
    for (auto p : {p1,p2}) {
        bool ok1 = (p.x >= cx1 && p.y >= cy1);  // 第一弧90~0
        bool ok2 = (p.x <= cx2 && p.y >= cy2);  // 第二弧180~90
        if (ok1 && ok2) {
            ld ang1=atan2(p.y-cy1,p.x-cx1);
            ld ang2=atan2(p.y-cy2,p.x-cx2);
            return make_tuple(p.x,p.y,ang1,ang2);
        }
    }
    // 默认返回第一个点
    ld ang1=atan2(p1.y-cy1,p1.x-cx1);
    ld ang2=atan2(p1.y-cy2,p1.x-cx2);
    return make_tuple(p1.x,p1.y,ang1,ang2);
}
int main()
{

    int n;
    while(cin>>r>>n&&(r||n)){

        c=2*r*PI;
        ld ans=0;
        ld x,y,mx=0,my=0;
        vector<node>aa;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            if(y>0){
                if(x<=r*2){
                    auto[fl,x1,y1,x2,y2,ox,oy,arc0to90]=aa.back();
                    
                    if(!fl&&eq(x1,x2)&&y2<y1){
                        aa.pop_back();
                        if(y1>=my+y){
                            y2=my+y;
                            mx+=x;
                            my+=y;
                            if(dist({x1,y1},{mx+x,my+y})>r){
                                aa.push_back({fl,x1,y1,x2,y2,ox,oy,arc0to90});
                            }
                            else{
                                auto& ce=aa.back();
                                auto [px,py,ang1,ang2]=intersectArcArc(ce.ox,ce.oy,mx,my);
                                if(py<my-y+r){
                                    aa.push_back({0,mx-x,my-y+r,mx,my-y+r});
                                }
                            }
                            aa.push_back({1,mx-r,my,mx,my+r,mx,my,0});
                        }
                        else{

                        }
                    }
                }
                else{
                    aa.push_back({0,mx,my+r,mx+x,my+r});
                    mx+=x;
                    aa.push_back({0,mx-r,my,mx-r,my+y});
                    my+=y;
                    aa.push_back({1,mx-r,my,mx,my+r,mx,my,0});
                }
                
            }
            else if(y<0){
                aa.push_back({0,mx,my+r,mx+x,my+r});
                mx+=x;
                aa.push_back({1,mx,my+r,mx+r,my,mx,my,1});
                if(-y>r){
                    aa.push_back({0,mx+r,my,mx+r,my+y+r});
                }
                my+=y;
            }
            else{
                aa.push_back({0,mx,my+r,mx+x,my+r});
                mx+=x;
            }
        }
    }
    return 0;
}