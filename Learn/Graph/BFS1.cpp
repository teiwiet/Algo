#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void BFS(vector<vector<int>> adj,int V,int s){
	vector<bool> visited(V+1,false);
	queue<int> q;
	visited[s] = true;
	q.push(s);

	while(!q.empty()){
		int u = q.front();
		cout << u << " ";
		q.pop();
		for(int v:adj[u]){
			if(!visited[v]){
				visited[v]=true;
				q.push(v);
			}
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
	BFS(adj,V,s);
	cout << endl;
}
