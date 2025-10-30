#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	if(n<=2){
		cout<<"1 2";
		return 0;
	}
	mp.resize(n+1, vector<int>(n+1));
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			cin >> mp[i][j];
			mp[j][i] = mp[i][j];
		}
	}

	int cnt = 0;
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(mp[i][j]==(i^j)){
				bool fl=1;
				for(int k=1; k<=n; k++){
					if(k!=j && k!=i)
					if(!(((mp[i][k]^j)==mp[j][k]||(mp[j][k]^i)==mp[i][k]))){
						// cout<<i<<" "<<j<<' '<<k<<"!\n";
						fl=0;
						break;
					}
				}
				if(fl)cout<<i<<" "<<j<<'\n';

			}
		}
	}
	return 0;
}