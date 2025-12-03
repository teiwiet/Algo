#include <bits/stdc++.h>
using namespace std;

int BFS(int N, int S, int T, vector<vector<int>>& adj) {
    const int INF = 1e9;
    vector<int> dist(N + 1, INF);
    queue<int> q;

    dist[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == T) return dist[u];  // tìm thấy T thì trả về luôn

        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return -1; // không có đường đi
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, S, T;
        cin >> N >> M >> S >> T;

        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << BFS(N, S, T, adj) << "\n";
    }

    return 0;
}

