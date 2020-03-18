#include <bits/stdc++.h>

using namespace std;

//Program
int main(int argc, char *argv[])
{
	string s;
	int R[1000010];
	int t; cin>>t;
	int done;
	getline(cin,s);
	while (t--){
		getline(cin,s);
		if(s.size() == 0){
			cout<<"YES"<<endl;
			continue;
		}
		if (s[s.size()-1] == '\r') s.erase(s.size()-1);
		if(s.size() % 2){
			cout<<"NO"<<endl;
			continue;
		}
//Oblicz promienie palindromow parzystych
		int x = 0;
		R[0] = 0;
		int k;
		for (int i = 0; i < s.size(); i+=k)
		{
			while (s[i - x] == s[i + x + 1])x++;
			R[i] = x;

//Algorytm Manachera
			k = 1;
			while (k <= x and R[i - k] != R[i] - k)
			{
				R[i + k] = min(R[i - k], (R[i] - k));
				k++;
			}
			x -= k;
			x = max(0, x);
		}
		done = -1;
		for (int i = 0; i < s.size()-1; ++i){
			if(R[i] >= i - done){
				i = done = 2 * i - done;
			}
		}
		if(done == s.size() - 1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
return 0;
}