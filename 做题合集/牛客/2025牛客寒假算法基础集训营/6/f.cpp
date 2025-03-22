#include<bits/stdc++.h>
using namespace std;
struct ID
{
    int id,a,b;
};
bool compare(const ID &x, const ID &y) {
    return x.a > y.a;
}
bool compareB(const ID &x, const ID &y) {
    return x.b+x.a > y.b+y.a;
}
int main()
{
    int N;
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        
        vector<ID> idsa(n);
        vector<ID> idsb(n);
        for(int i = 0; i < n; i++) {
            cin >> idsa[i].a >> idsa[i].b;            
            idsa[i].id = i;
        }
        idsb = idsa;
        sort(idsa.begin(), idsa.end(), compare);
        sort(idsb.begin(), idsb.end(), compareB);
        
        stack<ID> ss;
        ss.push(*idsa.begin());
        auto tt = idsb.begin();
        while(!ss.empty()) {
            ID current = ss.top();
            ss.pop();
            

        }
    }
    return 0;
}