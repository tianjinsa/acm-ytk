#include<bits/stdc++.h>
using namespace std;

vector<int> heap;
map<int,int> val_to_idx;


void heapifyUp(int idx) {
    while(idx > 0) {
        int parentIdx=(idx-1)/2;
        if(heap[idx] < heap[parentIdx]) {
            swap(heap[idx],heap[parentIdx]);
            swap(val_to_idx[heap[idx]],val_to_idx[heap[parentIdx]]);
            idx=parentIdx;
        } else {
            break;
        }
    }
}
void insert(int val) {
    heap.push_back(val);
    val_to_idx[val]=heap.size()-1;
    heapifyUp(heap.size()-1);
}

bool isRoot(int val) {
    if(heap.empty()) return 0;
    return heap[0]==val;
}

bool isbrother(int x,int y) {
    int idxX=val_to_idx[x];
    int idxY=val_to_idx[y];
    return (idxX-1)/2==(idxY-1)/2;
}

bool isParentOf(int x,int y) {
    int idxX=val_to_idx[x];
    int idxY=val_to_idx[y];
    return (idxY-1)/2==idxX;
}

bool isChildOf(int x,int y) {
    return isParentOf(y,x);
}

int main() {

    int n,m;
    cin>>n>>m;

    for(int i=0; i < n; ++i) {
        int val;
        cin>>val;
        insert(val);
    }

    cin.ignore();

    for(int i=0; i < m; ++i) {
        string line;
        getline(cin,line);
        stringstream ss(line);
        string token;
        int val1,val2;

        ss>>val1>>token;

        if(token=="is") {
            ss>>token>>token;
            if(token=="root") {
                cout<<(isRoot(val1) ? "T" : "F")<<endl;
            } else if(token=="parent") {
                ss>>token>>val2;
                cout<<(isParentOf(val1,val2) ? "T" : "F")<<endl;
            } else if(token=="child") {
                ss>>token>>val2;
                cout<<(isChildOf(val1,val2) ? "T" : "F")<<endl;
            }
        } else if(token=="and") {
            ss>>val2;
            cout<<(isbrother(val1,val2) ? "T" : "F")<<endl;
        }
    }

    return 0;
}