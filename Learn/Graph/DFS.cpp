#include <bits/stdc++.h>
using namespace std;
void DFS(const vector<vector<int>>& adj, int start){
    int V = adj.size();
    vector<bool> visited(V, false);
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        cout << u << " ";
        for(int i = (int)adj[u].size() - 1; i >= 0; i--){
            int v = adj[u][i];
            if(!visited[v]){
                visited[v] = true;
                st.push(v);
            }
        }
    }
    cout << "\n";
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto &list : adj)
        sort(list.begin(), list.end());
    DFS(adj, 0);

    return 0;
}
