#include<iostream>

using namespace std;

class node{
public:
	int k;
	node* left;
	node* right;
	node(int data){
		this->k = data;
		left = right = NULL;
	}
};


void inOrderPrint(node* root){
	if(root!=NULL){
		inorderPrint(root->left);
		cout << root->k << " ";
		inorderPrint(root->right);
	}
}

void postOrderPrint(node* root){
	if(root!=NULL){
			inorderPrint(root->right);
			cout << root->k << " ";
			inorderPrint(root->left);
	}
}

int height(node* root){
	if(root==NULL){
		return 0;
	}
	return max((root->left),(root->right))+1;
}

void printAtLevel(node* root,int k){
	if(root==NULL) return;
	if(k==0) cout << root->key;
	else{
		printAtLevel(root->left,k-1);
		printAtLevel(root->right,k-1);
	}
}

int main(){
	
}

