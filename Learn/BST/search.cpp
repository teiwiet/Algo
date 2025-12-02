#include<iostream>
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


node* insert(node* root,int x){
	if(root==NULL) return new node(x);
	else if(root->key < x){
		root->right = insert(root->right,x);
	}
	else if(root->key>x){
		root->left = insert(root->left,x);
	}
	return root;
}

bool search(node* root,int x){
	if(root==NULL) return false;
	else if(root->key==x){
		return true;
	}
	else if(root->key > x){
		return search(root->left,x);
	}
	else {
		return search(root->right,x);
	}
}

node* buildTree(vector<int> arr){
	node* root = NULL;
	for(int x : arr){
		root = insert(root,x);
	}
	return root;
}

void postOrder(node* root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->key << " ";
}

int main(){
	int n;
	cin >> n;
	vector<int> arr (n);
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	node* root = buildTree(arr);
	postOrder(root);
	cout << endl;
}
