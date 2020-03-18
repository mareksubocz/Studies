#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
typedef long long ll;
#include<bits/stdc++.h>
using namespace std;

ll GCD(ll a, ll b){
	if(a<b) swap(a, b);
	while(b){
		ll c = a % b;
		a = b;
		b = c;
	}
	return a;
}

ll NWW(ll a, ll b){
	if(a<1 or b<1)
		throw string("All arguments should be greater than zero!");
	return a / GCD(a,b) * b;
}

void validateString(string s){
	for (int i = 0; i < s.size(); ++i){
		if(s[i] < '0' or s[i] > '9')
			throw string("to nie jest calkowita liczba dodatnia ziom");
	}
	if(s[0] == '0')
		throw string("liczby nie zaczynaj od 0");
	if(s.size() > 9)
		throw string("arguments are too large!");
}
ll stringToLL(string s){
	ll result = 0;
	for (int i = 0; i < s.size(); ++i){
		result *= 10;
		result += s[i] - 48;
	}
	return result;
}
void flow(){
	try{
		ll a, b;
		string s1, s2;
		cin>>s1>>s2;
		validateString(s1);
		validateString(s2);
		a = stringToLL(s1);
		b = stringToLL(s2);
		ll result = NWW(a,b);
		cout<<result<<endl;
	}catch(string ex){
		cout<<ex<<endl;
	}
	catch(...){
		cout<<"please dont call us"<<endl;
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	while(1)
		flow();
	return 0;
}