#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > v;
int n;

bool findpath(int w) {
	cout<<"w: "<<w<<endl;
	for (int i = 0; i < v.size(); ++i){
		for (int j = 0; j < v[i].size(); ++j)
			cout<<v[i][j]<<",";
		cout<<endl;
	}
	for (int i = 0; i < v[w].size(); ++i)
		if (v[w][i] > w) {
			if (v[w][i] == n - 1) {		//jezeli dotarlismy do konca
				v[w].erase(v[w].begin() + i);
				return true;
			}
			if (findpath(v[w][i])) {
				if (w == 0)	//jezeli wyszlismy z poczatku
					v[w].erase(v[w].begin() + i);
				return true;
			}
		}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	int t; cin >> t;
	vector<int> tmp;
	int result;
	int ile, a;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n-1; ++i) {
			cin >> ile;
			for (int j = 0; j < ile; ++j) {
				cin >> a;
				tmp.push_back(a - 1);	//teraz sa numerowane od 0 do 1
			}
			v.push_back(tmp);
			tmp.clear();
		}
		result = 0;
		while (findpath(0)){
			result++;
		}
		cout << result << endl;
		v.clear();
	}
	return 0;
}

//while(findpath) result++;