#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 100000
#include<bits/stdc++.h>
using namespace std;

map<string, int> cities;
int n,cars,edges;

int droga[1001][1001] = {INF};

void addCity(string c){
	if(cities.find(c) == cities.end()){
		cities.insert(pair<string,int>(c,cities.size()));
	}
}

void floydwarshall() {
for (int k = 0; k < n; k++)
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			droga[i][j] = min(droga[i][j], droga[i][k]+droga[k][j]);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	string s;
	int t = 1, wynik, a, b, l;
	char c, d, e;
	int targets[1001];
	while (1){
		//*****************wczytywanie***************************
		cin>>n>>cars>>edges;
		if(!n){
			break;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				droga[i][j] = INF;
		cities.clear();
		for (int i = 0; i <= cars; ++i){
			cin>>s;
			addCity(s);
			targets[i] = cities[s];
		}
		for (int i = 0; i < edges; ++i){	//wczytywanie polaczen
			cin>>s;
			addCity(s);
			a = cities[s];
			cin>>d>>c>>l>>c>>e>>s;
			addCity(s);
			b = cities[s];
			if(d == '<')
				droga[b][a] = min(droga[b][a],l);
			if(e == '>')
				droga[a][b] = min(droga[a][b],l);
		}
		//*****************wczytywanie***************************

		floydwarshall();
		wynik = 0;
		for (int i = 1; i <= cars; ++i)
			if(targets[i])	//jezeli auto nie jest juz w garazu
				wynik += droga[targets[i]][targets[0]] + droga[targets[0]][targets[i]];
		cout<<t<<". "<<wynik<<endl;
		t++;
	}
	return 0;
}
