#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	int n, q;
	int a[100001] = {0};
	int s, e;
	int suma, wynik;
	bool tryb;
	cin>>n>>q;
	for (int i = 0; i < q; ++i){
		cin>>tryb;
		cin>>s>>e;
		if(!tryb){
			a[s]++;
			if(a[s] % 3 == 0)
				a[s] = 0;
			if(e < n-1){
				a[e+1]--;
				if(a[e+1] % 3 == 0)
					a[e+1] = 0;
			}

		}
		else{
			suma = wynik = 0;
			for (int i = 0; i <= e; ++i){
				suma += a[i];
				if(suma % 3 == 0 && i >= s){
					suma = 0;
					wynik++;
				}
			}
			cout<<wynik<<endl;
		}
	}
	return 0;
}