#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class node{
public:
	int key;
	node* left;
	node* right;
	node(int data){
		this->key = data;
		left=right=NULL;
	}
};


node* buildTree(vector<int> arr){
	node* root = new node(arr[0]);
	queue<node*> q;
	q.push(root);
	int i= 1;
	while(!q.empty() && i<arr.size()){
		node* curr = q.front();
		q.pop();

		if(arr[i]!=-1){
			curr->left = new node(arr[i]);
			q.push(curr->left);
		}
		i++;
		if(i>=arr.size()) break;
		if(arr[i]!=-1){
			curr->right = new node(arr[i]);
			q.push(curr->right);
		}
		i++;
	}
	return root;
}

void inOrderPrint(node* root){
	if(root==NULL) return;
	inOrderPrint(root->left);
	cout << root->key << " ";
	inOrderPrint(root->right);
}

void preOrderPrint(node* root){
	if(root==NULL) return;
	cout << root->key << " ";
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}


void postOrderPrint(node* root){
	if(root==NULL) return;
	postOrderPrint(root->left);
	postOrderPrint(root->right);
	cout << root->key << " ";
}

int main(){
	vector<int> arr {1,2,3,4,5};
	node* root = buildTree(arr);
	postOrderPrint(root);
}
