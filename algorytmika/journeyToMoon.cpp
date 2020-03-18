#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ROF(i,a,b) for(int i=a; i>b; --i)
#define REP(i,n) FOR(i,0,n)
#define INF 2147483647
#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &edges, vector <bool> &visited, int vertex){
    if (visited[vertex] == true)
        return 0;

    visited[vertex] = true;
    int count = 1;
    for (size_t i=0; i < edges[vertex].size(); ++i) {
        count += dfs(edges, visited, edges[vertex][i]);
    }
    return count;
}

int main(){
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<bool> visited(numVertices);
    vector<vector <int>> edges(numVertices);

    while (numEdges--) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    int sum = 0;
    int alreadySeen = 0;
    for (long i=0; i<numVertices; ++i) {
        if (!visited[i]) {
            int count = dfs(edges, visited, i);
            sum = sum + (alreadySeen * count);
            alreadySeen += count;
        }
    }
    cout<<sum<<endl;
    return 0;
}