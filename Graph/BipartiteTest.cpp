#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph;

bool isBipartite(graph& g){
    int n = g.size();

    vector<int> color(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    color[0] = visited[0] = 1;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int u:g[v]){
            if(color[u] == color[v]) return false;

            if(!visited[u]){
                color[u] = !color[v];
                visited[u] = true;
                q.push(u);
            }
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, edges;

    cin >> n >> edges;

    // ! 0-indexado ! 
    graph g(n);

    for(int i=0; i<edges; ++i){
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << (isBipartite(g)?"YES":"NO") << '\n';

    return 0;
}