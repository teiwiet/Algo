#include<iostream>
#include<vector>
using namespace std;

void DFS(int u,vector<vector<int>>& adj,vector<bool>& visited){
	visited[u] = true;
	cout << u << " ";

	for(int v:adj[u]){
		if(!visited[v]){
			DFS(v,adj,visited);
		}
	}
}


int main(){
	int V,E;
	cin >> V >> E;
	vector<vector<int>> adj(V+1);
	
	for(int i = 0;i<E;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int s;
	cin >> s;
	vector<bool> visited(V+1,false);

	DFS(s,adj,visited);
	cout << endl;
}
