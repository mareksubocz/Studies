#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

bool myfunction(string a, string b){
	for (int i = 0; i < a.size(); ++i){
		if(i >= a.size())
			return 1;
		if(i >= b.size())
			return 0;
		if(a[i] < b[i])
			return 1;
		if(a[i] > b[i])
			return 0;
	}
	return 0;
}

bool znaleziono;
vector<string> doWypisania;

struct node{
	char c;
	bool b;
	vector< node* > v;
};

void szukajSlow(node * n, string slowo){
	for (int i = 0; i < n->v.size(); ++i){
		if(n->v[i]->b){
			// cout<<slowo<<n->v[i]->c<<endl;
			doWypisania.push_back(slowo+n->v[i]->c);
			znaleziono = true;
		}
		szukajSlow(n->v[i], slowo+n->v[i]->c);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	int n, q;
	node root;
	node * prevNode;
	node * newNode;
	string slowo;
	root.b = 0;
	cin>>n;
	for (int in = 0; in < n; ++in){
		prevNode = &root;
		cin>>slowo;
		for (int i = 0; i < slowo.length(); ++i){
			for (int j = 0; j < prevNode->v.size(); ++j){
				if(prevNode->v[j]->c == slowo[i]){	//jezeli jest juz taka literka
					newNode = prevNode->v[j];
					goto spoko;
				}
			}
			newNode = new node;
			prevNode->v.push_back(newNode);
			newNode->c = slowo[i];
			spoko: ;
			if (i == slowo.size()-1){
				newNode->b = true;
			}
			prevNode = newNode;
		}
	}
	//koniec ustawiania drzewa
	cin>>q;
	for (int iq = 0; iq < q; ++iq){
		prevNode = &root;
		cin>>slowo;
		cout<<"Case #"<<iq+1<<":"<<endl;
		for (int i = 0; i < slowo.size(); ++i){
			znaleziono = false;
			for (int j = 0; j < prevNode->v.size(); ++j){
				if(prevNode->v[j]->c == slowo[i]){
					prevNode = prevNode->v[j];
					znaleziono = true;
				}
				if(i == slowo.size()-1 && znaleziono){
					znaleziono = false;
					szukajSlow(prevNode, slowo);
				}
			}
		}
		sort(doWypisania.begin(), doWypisania.end(), myfunction);
		if(!doWypisania.size())
			cout<<"No match."<<endl;
		else
			for (int i = 0; i < doWypisania.size(); ++i)
				cout<<doWypisania[i]<<endl;
		doWypisania.clear();
	}
	return 0;
}