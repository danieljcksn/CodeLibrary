#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph;

void bfs(int root, graph& g){
    vector<bool> visited(g.size()+1, false);

    queue<int> q;
    q.push(root);
    visited[root] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int u:g[v]){
            if(!visited[u]){
                q.push(u);
                visited[u] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, edges;
    cin >> n >> edges;

    //1-indexado
    graph g(n+1);

    for(int i=0, a, b; i<edges; ++i){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }    

    bfs(1, g);

    return 0;
}