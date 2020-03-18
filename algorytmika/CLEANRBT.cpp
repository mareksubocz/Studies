#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

char a[30][30] = {{'-'}};
bool vis[30][30];
int e[20][20];
int start;
map<int, int> m;

void bfs(int fy, int fx) {
	queue<pair<int, int> > q; //pierwsze to polaczone indeksy, drugie odleglosc
	q.push(pair<int, int>(fy * 100 + fx, 0));
	vis[fy][fx] = 1;
	int y, x;
	pair<int, int> p;
	while (!q.empty()) {
		p = q.front(); q.pop();
		y = p.first / 100; x = p.first % 100;
		if (a[y][x] == 'o' or a[y][x] == '*') {
			e[m[fy * 100 + fx]][m[p.first]] = p.second;	//key mapy to polaczone indeksy
		}
		if ( (a[y][x + 1] == '.' or a[y][x + 1] == 'o' or a[y][x + 1] == '*') and !vis[y][x + 1])
			q.push(pair<int, int>(( y * 100 + x + 1), p.second + 1)), vis[y][x + 1] = 1;
		if ( (a[y][x - 1] == '.' or a[y][x - 1] == 'o' or a[y][x - 1] == '*') and !vis[y][x - 1])
			q.push(pair<int, int>(( y * 100 + x - 1), p.second + 1)), vis[y][x - 1] = 1;
		if ( (a[y + 1][x] == '.' or a[y + 1][x] == 'o' or a[y + 1][x] == '*') and !vis[y + 1][x])
			q.push(pair<int, int>(( (y + 1) * 100 + x), p.second + 1)), vis[y + 1][x] = 1;
		if ( (a[y - 1][x] == '.' or a[y - 1][x] == 'o' or a[y - 1][x] == '*') and !vis[y - 1][x])
			q.push(pair<int, int>(( (y - 1) * 100 + x), p.second + 1)), vis[y - 1][x] = 1;
	}
}
// przerob tak zeby byl bufor na poczatku i na koncu tablicy
int main() {
	std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);

	vector<int> kolejnosc;
	vector<int> kk;
	int mini, wynik;
	int xs, ys;
	while (cin >> xs >> ys and (xs + ys)) {
		//********czyszczenie***************
		for (int i = 0; i < ys+2; ++i)
			for (int j = 0; j < xs+2; ++j)
				a[i][j] = '-';
		m.clear();
		for (int i = 0; i < 20; ++i)
			for (int j = 0; j < 20; ++j)
				e[i][j] = -1;
			kolejnosc.clear();
		//********czyszczenie***************
		for (int i = 1; i < ys + 1; ++i)
			for (int j = 1; j < xs + 1; ++j) {
				cin >> a[i][j];
				if (a[i][j] == '*' or a[i][j] == 'o')
					m.insert(pair<int, int>(i * 100 + j, m.size()));
				if (a[i][j] == 'o')
					start = i * 100 + j;
			}
		for (int i = 1; i < ys + 2; ++i)
			for (int j = 1; j < xs + 2; ++j)
				if (a[i][j] == '*' or a[i][j] == 'o') {
					for (int k = 0; k < ys+2; ++k)
						for (int l = 0; l < xs+2; ++l)
							vis[k][l] = 0;
					bfs(i, j);
				}
		for (int i = 0; i < m.size(); ++i)
			for (int j = 0; j < m.size(); ++j)
				if (e[i][j] == -1) {
					cout << -1 << endl;
					goto end;
				}
		for (int i = 0; i < m.size(); ++i)
			if(m[start] != i)
				kolejnosc.push_back(i);
		mini = INF;
	  do {
	  	kk = kolejnosc;
	  	kk.insert(kk.begin(), m[start]);
	  	wynik = 0;
	    for (int i = 0; i < m.size()-1; ++i){
	    	wynik += e[kk[i]][kk[i+1]];
	    }
	    if(wynik < mini)
	    	mini = wynik;
	  } while ( next_permutation(kolejnosc.begin(),kolejnosc.end()) );
		cout << mini << endl;
		end:;
	}
	return 0;
}
