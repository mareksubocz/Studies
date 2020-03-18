#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

struct droga{
	int m1;
	int m2;
	int cost;
	int idx;
	bool czyWybrane;
};

int miasto[70010];	//zdeklaruj roznokolorowo;
int m, n;

bool czyJuz(){
	for (int i = 1; i < m; ++i)
		if(miasto[i] != miasto[0])
			return false;
	return true;
}

bool comp(droga a, droga b){
	if(a.cost < b.cost)
		return true;
	return false;
}

bool comp2(droga a, droga b){
	if(a.idx < b.idx)
		return true;
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	droga d[300010];
	int prevcolor;
	cin>>m>>n;
	for (int i = 0; i < m; ++i)
		miasto[i] = i;
	for (int i = 0; i < n; ++i){
		cin>>d[i].m1>>d[i].m2>>d[i].cost;
		d[i].m1--; d[i].m2--;
		d[i].idx = i;
		d[i].czyWybrane = false;
	}
	stable_sort(d, d+n, comp);
	for (int i = 0; !czyJuz(); ++i){
		if(miasto[d[i].m1] != miasto[d[i].m2]){
			d[i].czyWybrane = true;
			for (int j = 0; j < n; ++j)
				if(d[j].cost == d[i].cost)
					if((miasto[d[j].m1] == miasto[d[i].m1] and miasto[d[j].m2] == miasto[d[i].m2])
					or (miasto[d[j].m1] == miasto[d[i].m2] and miasto[d[j].m2] == miasto[d[i].m1]))
						d[j].czyWybrane = true;
			prevcolor = miasto[d[i].m2];
			for (int j = 0; j < m; ++j)
				if(miasto[j] == prevcolor)	//polacz kolory
					miasto[j] = miasto[d[i].m1];
		}
		if(i == n-1)	//sprawdzamy znowu trasy ktore odrzucilismy
			i = -1;
	}
	stable_sort(d,d+n,comp2);
	for (int i = 0; i < n; ++i){
		if(d[i].czyWybrane)
			cout<<"TAK"<<endl;
		else cout<<"NIE"<<endl;
	}
	return 0;
}