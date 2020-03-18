#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

bool vis[100002];
bool used[100002];
int e[50002][50002];

int k, b, t;									//0 - szukamy wolnej krawedzi
bool dfs(int n, bool tryb){ 	 		//0 - jak znajdziemy wolny node, konczymy
	vis[n] = true;
	if(n < k){		//jezeli to krowa
		if(!tryb){			// jezeli mamy 0
			for (int i = 0; i < b; ++i)
				if(e[n][i] == 1 and !used[k+i] and !vis[k+i]){ //wolna krawedzia do wolnego, wybieram
					used[k+i] = used[n] = true;
					e[n][i] = 2;
					return true;
				}
				else if(e[n][i] == 1 and used[k+i] and !vis[k+i]) 	//z wolnego do pelnego
					if(dfs(k+i, 1-b)){
						used[n] = true;
						e[n][i] = 2;
						return true;
					}
		}else				//jezeli mamy 1
			for (int i = 0; i < b; ++i)
				if(e[n][i] == 2 and !vis[k+i])
					if(dfs(k+i, 1-b)){
						used[n] = true;
						e[n][i] = 1;
						return true;
					}
	}else{					//jezeli byk
		if(!tryb){			// jezeli mamy 0
			for (int i = 0; i < k; ++i)
				if(e[i][n-k] == 1 and !used[i] and !vis[i]){ //wolna krawedzia do wolnego, wybieram
					used[i] = used[n] = true;
					e[i][n-k] = 2;
					return true;
				}
				else if(e[i][n-k] == 1 and used[i] and !vis[i]) 	//z wolnego do pelnego
					if(dfs(i, 1-b)){
						used[n] = true;
						e[i][n-k] = 2;
						return true;
					}
		}else	{			//jezeli mamy 1
			for (int i = 0; i < k; ++i)
				if(e[i][n-k] == 2 and !vis[i])
					if(dfs(i, 1-b)){
						used[n] = true;
						e[i][n-k] = 1;
						return true;
					}
		}
	}
	return false;
}


int main(){
	std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	cin>>k>>b>>t;
	int x, y;
	while (t--){
		cin>>x>>y;
		x--; y--;
		e[x][y] = 1;
	}
	
	for (int i = 0; i < k+b; ++i)
		if(!used[i]){
			for (int j = 0; j < k+b; ++j)
				vis[j] = 0;		
			dfs(i, 0);
		}

	int wynik = 0;
	for (int i = 0; i <= k+b; ++i)
		if(used[i] == 1)
			wynik++;
	cout<<wynik/2<<endl;
	return 0;
}