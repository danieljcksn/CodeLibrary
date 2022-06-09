#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph;
vector<bool> visited;

void dfs(graph& g, int v){
    visited[v] = true;

    for(int u:g[v]){
        if(!visited[u]){
            dfs(g, u);
        }
    }
}

int main(){
    int n, edges;
    cin >> n >> edges;

    graph g(n+1);

    for(int i=0, a, b; i<edges; ++i){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }    

    visited.assign(n+1, false);
    dfs(g, 1);

    return 0;
}