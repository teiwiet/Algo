#include<iostream>

using namespace std;

void BFS(vector<int> adj[],int V,int s){
	bool visited[V+1];
	for(int i = 0;i<V;i++){
		visited[i] = false;
	}
	queue<int> q;
	visited[s] = true;
	q.push(s);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		cout << u << " ";
		for(int v: adj[u]){
			if(visited[v]==false){
				visited[v] = true;
				q.push(v);
			}
		}
	}
}


int main(){

}
