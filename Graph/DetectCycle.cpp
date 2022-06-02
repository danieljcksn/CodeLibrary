#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph;
vector<bool> visited, recStack;
bool cicle;

//Undirected graph
void bfs(int root, graph& g){
    int n = g.size();
    visited.assign(n+1, false);
    vector<int> parent(n+1, -1);

    queue<int> q;
    visited[root] = true;
    q.push(root);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int u:g[v]){
            if(!visited[u]){
                q.push(u);
                parent[u] = v;
                visited[u] = true;
            }else if(parent[u] != v){
                cicle = true;
            }
        }
    }
}

//Directed graph
void dfs(const graph& g, int v){ 
    visited[v] = recStack[v] = true; //O vértice atual entrou na pilha de recursão

    for(int u:g[v]){
        if(!visited[u]){
            dfs(g, u);
        }
        else if(recStack[u]){
            cicle = true; //O vértice atual já foi visitado e ainda está na pilha de recursão (há uma aresta de volta pra ele)
        }
    }
    
    recStack[v] = false; //O vértice v não está mais na pilha de recursão atual
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
        //undirected? g[b].push_back(a);
    }    

    cicle = false;
    visited.assign(n+1, false);
    recStack.assign(n+1, false);
    dfs(g, 1);

    return 0;
}