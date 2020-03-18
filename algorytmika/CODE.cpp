#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

int e[100000][10];
int lista[1100000];
int listasize;

void cyklEulera(int v){
    int a,b;
    while(1){
        a = 0;
        bool found=false;
        while (a < 10 and !found){
            b = e[v][a];
            if (b >= 0)
                found=true;
            a++;
        }
        if (!found) break;
        e[v][a-1] = -1;
        cyklEulera(b);
    }
    lista[listasize++] = v % 10;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    int n;
    hbhkbbk
    while (1){
        cin>>n;
        if (n == 0) break;
        if (n == 1){ cout<<"0123456789"<<endl; continue; }
        int p10 = 1;
        for (int i = 1; i < n; ++i)
            p10 *= 10;
        for (int i = 0; i < p10; ++i)
            for (int j = 0; j < 10; ++j)
                e[i][j] = 10 * (i % (p10/10)) + j;      //kodowanie odp
        listasize=0;
        cyklEulera(0);
        for (int i = 0; i < n-2; ++i)
            cout<<0;
        for (int i = listasize-1; i >= 0; i--)
            cout<<lista[i];
        cout<<endl;;
    }
    return 0;
}
