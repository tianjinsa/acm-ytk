#include<bits/stdc++.h>
using namespace std;
using lf=long double;
lf PI=acos(-1);
lf r,c;

lf arcx(lf dy){//弦长求最小圆心距离
    return r*sin(PI/2-asin((r-dy)/r));
}
lf arcl(lf dx,lf dy){//弦长求弧长
    return r*(2*asin(sqrt(dx*dx+dy*dy)/(2*r)));
}
static const lf EPS = 1e-9;
inline bool eq(lf a, lf b) { return fabsl(a - b) < EPS; }// a == b
inline bool le(lf a, lf b) { return a - b <= EPS; }// a <= b
inline bool ge(lf a, lf b) { return a - b >= -EPS; }// a >= b
inline bool lt(lf a, lf b) { return a - b < -EPS; }// a < b
inline bool gt(lf a, lf b) { return a - b > EPS; }// a > b
int main()
{
    int n;
    int nn=1;
    while(cin>>r>>n&&(r||n)){
        c=2*r*PI;
        lf x,y,mx=0,my=0,ans=0;
        vector<tuple<bool,lf,lf,lf>> v;
        for(int i=0;i<n;i++){
            
            cin>>x>>y;
            v.push_back({0,my,mx,mx+x});
            mx+=x;
            v.push_back({1,mx,my,my+y});
            my+=y;
        }
        auto&[fl,xy,d1,d2]=v[0];
        mx=(d2-d1)-r,my=r;
        ans+=(d2-d1)-r;
        n=v.size();
        for(int i=1;i<n;i++){
            auto &[fl,xy,d1,d2]=v[i];
            if(fl){//垂直
                if(d2<d1){//向下
                    lf h = d1 - d2;
                    lf bestAngle = PI;
                    int bestJ = i;
                    int m2 = v.size();
                    for(int j = i+1; j < m2; j++){
                        auto& [fl2, xy2, d12, d22] = v[j];
                        lf dx = fabsl(xy2 - xy);
                        if(dx > 2*r) break;
                        if(fl2){
                            lf dh = d22 - d12;
                            if(dh > 0 && dh < h){
                                lf ang = acos((r-h)/r) + acos((r-dh)/r);
                                if(ang < bestAngle){ bestAngle = ang; bestJ = j; }
                            }
                        } else {
                            lf dh = xy2 - d2;
                            if(dh >= -EPS) {
                                lf ang = acos((r-h)/r);
                                lf xHit = xy + r * sin(ang);
                                if(xHit + EPS >= min(d12, d22) && xHit <= max(d12, d22) + EPS){ bestAngle = ang; bestJ = j; }
                            }
                        }
                    }
                    // 如果旋转90度内无碰撞，则垂直下降至水平边
                    if(bestAngle >= PI/2) {
                        lf drop = 1e18;6
                        int hitJ = -1;
                        for(int j = i+1; j < m2; j++){
                            auto& [fl2, xy2, d12, d22] = v[j];
                            if(!fl2){
                                if(mx + EPS >= d12 && mx <= d22 + EPS){
                                    lf dropDist = my - (xy2 + r);
                                    if(dropDist > EPS && dropDist < drop){ drop = dropDist; hitJ = j; }
                                }
                            }
                        }
                        if(hitJ != -1){
                            ans += drop;
                            my -= drop;
                            i = hitJ;
                            continue;
                        }
                    }
                    ans += r * bestAngle;
                    // 若落在上升沿，旋转至最近水平边
                    auto& [flB, xyB, d1B, d2B] = v[bestJ];
                    if(flB && d2B > d1B) {
                        lf dh2 = d2B - d1B;
                        lf ang2 = acos((r - dh2)/r);
                        ans += r * ang2+r;
                        mx = xyB + r;
                        my = d2B + r;
                    }
                    else{
                        mx = d1B+r;
                        ans+=r-arcx(d1-xyB);
                        my = xyB+r;
                    }
                    i = bestJ;
                }
                else{//向上
                    lf need=arcx(d2-d1);
                    mx+=r+r;
                    my+=d2-d1;
                    ans+=r-need+r;
                    if(r>d2-d1){//台阶小于半径
                        ans+=arcl(need,d2-d1);
                    }
                    else{//台阶大于等于半径
                        ans+=PI/2*r+(d2-d1-r);
                    }
                }
            }
            else{
                ans+=d2-d1-r*2;
                mx+=d2-d1-r*2;
            }
        }
        cout<<fixed<<setprecision(3)<<"Case "<<nn++<<": Distance = "<<ans<<endl;
    }
    return 0;
}