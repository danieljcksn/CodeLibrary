#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph;
vector<bool> visited, recStack;
vector<int> ans;
bool cicle;

void dfs(const graph& g, int v){ 
    if(cicle) return;
    visited[v] = recStack[v] = true;

    for(int u:g[v]){
        if(!visited[u]){
            dfs(g, u);
        }
        else if(recStack[u]){
            cicle = true;
        }
    }
    
    recStack[v] = false;
    ans.push_back(v);
}

void topologicalSort(const graph& g){
    int n = g.size();
    ans.clear();
    visited.assign(n, false);
    recStack.assign(n, false);
    cicle = false;

    for(int i=0; i<n && !cicle; ++i){
        if(!visited[i]) dfs(g, i);
    }

    if(!cicle) reverse(ans.begin(), ans.end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, edges;
    cin >> n >> edges;

    //0-indexado
    graph g(n);

    for(int i=0, a, b; i<edges; ++i){
        cin >> a >> b;
        g[--a].push_back(--b);
    }    

    topologicalSort(g);

    if(cicle) cout << "Has a cycle!\n";
    else{
        for(int i:ans) cout << i << '\n'; //Lembrete: tá 0-indexado '-'
    }

    return 0;
}