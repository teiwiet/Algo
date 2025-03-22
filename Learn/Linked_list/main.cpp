#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int data){
		this->data = data;
		next = NULL;
	}
};

void insertAtHead(node* &head,int data){
	if(head==NULL){
		head = new node(data);
		return;
	}
	node* n = new node(data);
	n->next = head;
	head = n;
}

void printLL(node* head){
	while(head!=NULL){
		cout << head->data<< "->";
		head = head->next;
	}
	cout << "\n";
}

void deleteHead(node* &head){
	if(head==NULL){
		return ;
	}
	node* temp = head->next;
	delete head;
	head = temp;
}

bool search(node* head,int target){
	while(head!=NULL){
		if(head->data==target){
			return true;
		}
		head = head->next;
	}
	return false;
}

bool searchRecusive(){

}

int main(){
	node* head = NULL;
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);
	printLL(head);
	int target;
	cin >> target;
	if(search(head,target)){
		cout << "found element\n";
	}
	else{
		cout << "not found\n";
	}
	return 0;
}
