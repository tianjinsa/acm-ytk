#include<bits/stdc++.h>
using namespace std;

vector<int> pos;
vector<int> aim;
vector<vector<int>> raim;
vector<bool> dir;
vector<long long> stop;
int vt;
void dfs(int a){
	stack<int> s;
	s.push(a);
	while(!s.empty()){
		int u=s.top();
		s.pop();
		for(auto &v:raim[u]){
			if(stop[v]==LLONG_MAX){
				long long dist=(dir[v]==dir[u]?LLONG_MAX:abs(pos[v]-pos[u])/2);
				if(stop[u]<dist){
					if(dist==LLONG_MAX){
						stop[v]=stop[u]+abs(pos[v]-pos[u]);
					}
					else {
						stop[v]=dist*2-stop[u];
					}
				}
				else{
					stop[v]=dist;
				}
				s.push(v);
				vt--;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	pos.resize(n);
	aim.resize(n);
	raim.resize(n);
	dir.resize(n);
	stop.resize(n,LLONG_MAX);
	for(int i=0;i<n;i++){
		cin>>aim[i];
		aim[i]--;
		raim[aim[i]].emplace_back(i);
	}
	for(int i=0;i<n;i++){
		cin>>pos[i];
		pos[i]*=2;
	}
	for(int i=0;i<n;i++){
		dir[i]=(pos[aim[i]]<pos[i]);
	}
	vt=n;
	vector<pair<long long,int>> pq;
	pq.reserve(n);
	for(int i=0;i<n;i++){
		int &v=aim[i];
		if(dir[i]!=dir[v]){
			pq.emplace_back(abs(pos[v]-pos[i])/2,i);
		}
	}
	sort(pq.begin(),pq.end());
	for(auto &[dt,min_index]:pq){
		if(stop[min_index]!=LLONG_MAX){
			continue;
		}
		stop[min_index]=dt;
		dfs(min_index);
		vt--;
		if(vt==0){
			break;
		}
	}

	for(int i=0;i<n;i++){
		cout<<stop[i]<<' ';
	}
	return 0;
}