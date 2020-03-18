#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	int p[200010][200010];
	int n; cin>>n;
	int t; cin>>t;
	int a, b;
	int maxi;
	bool operacja;
	while (t--){
		cin>>operacja;
		if(operacja){
			cin>>a>>b;
			for (int i = 0; i <= a; ++i)
				for (int j = a; j < n; ++j)
					if(p[i][j] < b)
						p[i][j] = b;
			p[a] = b;
		}	
		else{
			cin>>a>>b;
			maxi = -INF;
			for (int i = a; i <= b; ++i){
				if(p[i] > maxi)
					maxi = p[i];
			}
			cout<<maxi<<endl;
		}
	}
	return 0;
}