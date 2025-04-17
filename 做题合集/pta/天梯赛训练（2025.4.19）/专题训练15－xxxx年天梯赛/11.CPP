#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int v;
    treenode*left,*right;
    treenode(int x):v(x),left(0),right(0){}
};
map<int,int>mp;
int main()
{
    int n;
    cin>>n;
    n--;
    int t;
    cin>>t;
    mp[0]++;
    treenode*root=new treenode(t);
    while(n--){
        cin>>t;
        treenode*nn=new treenode(t);
        stack<treenode*>q;
        q.push(root);
        while(1){
            treenode*now=q.top();
            if(t<=now->v){
                if(now->left){
                    q.push(now->left);
                }else{
                    now->left=nn;
                    mp[q.size()]++;
                    break;
                }
            }
            else{
                if(now->right){
                    q.push(now->right);
                }else{
                    now->right=nn;
                    mp[q.size()]++;
                    break;
                }
            }
        }
    }
    int last=prev(mp.end())->first;
    cout<<mp[last]+mp[last-1]<<endl;
    return 0;
}