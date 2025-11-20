#include <bits/stdc++.h>
using namespace std;
void BFS(const vector<vector<int>>& adj, int start){
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

int main(){
    int V, E, start;
    cin >> V >> E >> start;
    vector<vector<int>> adj(V);
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto &list : adj)
        sort(list.begin(), list.end());
    BFS(adj, start);
    return 0;
}
