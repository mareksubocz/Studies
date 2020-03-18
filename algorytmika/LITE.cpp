#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	int n; cin>>n;
	int t; cin>>t;
	int wynik;
	bool operacja;
	bool l[4194304] = {0};
	int a, b;
	while (t--){
		cin>>operacja;
		if(!operacja){
			cin>>a>>b;
			l[a] = 1 - l[a];
			l[b+1] = 1 - l[b+1];
		}
		else{
			operacja = 0;
			wynik = 0;
			cin>>a>>b;
			for (int i = 0; i <= b; ++i){
				if(l[i])
					operacja = 1 - operacja;
				if(operacja and i >= a and i <= n)
					wynik++;
			}
			cout<<wynik<<endl;
		}
	}
	return 0;
}