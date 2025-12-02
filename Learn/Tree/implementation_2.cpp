#include<iostream>
#include<climits>
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

	int i = 1;
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
int heightBT(node* root){
	if(root==NULL) return 0;
	return 1+max(heightBT(root->left),heightBT(root->right));
}
bool findInTree(node* root,int target){
	if(root==NULL) return false;
	if(root->key==target) return true;
	return findInTree(root->left,target) || findInTree(root->right,target);
}
void printAtKDistance(node* root,int k){
	if(root==NULL) return;
	if(k==0){
		cout << root->key;
	}
	else{
		printAtKDistance(root->left,k-1);
		printAtKDistance(root->right,k-1);
	}
}
void levelOrderTraversal(node* root){
	if(root==NULL) return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		int count = q.size();
		for(int i = 0;i<count;i++){
			node* curr = q.front();
			q.pop();
			cout << curr->key;
			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);
		}
		cout << "\n";
	}
}
int maxInTree(node* root){
	if(root==NULL) return INT_MIN;
	return max(root->key,max(maxInTree(root->left),maxInTree(root->right)));
}


int main(){
	vector<int> arr {1,2,3,4,5};
	node* root = buildTree(arr);
	cout << "max in tree : " << maxInTree(root);
}
