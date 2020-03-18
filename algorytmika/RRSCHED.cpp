#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

struct process{
  int x;
  int pos;
  int originalPos;
  int timeOut;
};

int prevTime, prevPos;
vector<process> poriginal, p;

void liczCzas(){
  process f = p.back();
  p.pop_back();
  f.timeOut = prevTime+ (f.x-1)*p.size() + f.pos + 1 - prevPos;
  for (int i = 0; i < p.size(); ++i){
    p[i].x -= f.x;
    if(p[i].pos > f.pos){
      p[i].x++;
      p[i].pos--;
    }
    if(p[i].pos < prevPos and p[i].pos < f.pos)
      p[i].x++;
  }
  for (int i = 0; i < p.size(); ++i) cout<<p[i].x<<",";
    cout<<endl;
  poriginal[f.originalPos].timeOut = f.timeOut;
  prevTime = f.timeOut;
  prevPos = f.pos;
}

bool comp(process a, process b){
  if(a.x < b.x)
    return false;
  return true;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  //std::cin.tie(nullptr);
  int n, a; cin>>n;
  process tmp;
  for (int i = 0; i < n; ++i){
    cin>>a;
    tmp.x = a;
    tmp.pos = tmp.originalPos = i;
    poriginal.push_back(tmp);
  }
  p = poriginal;
  stable_sort(p.begin(), p.end(), comp);
  while (!p.empty())
    liczCzas();
  for (int i = 0; i < poriginal.size(); ++i)
    cout<<poriginal[i].timeOut<<endl;
  return 0;
}