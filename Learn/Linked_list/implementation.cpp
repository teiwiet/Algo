#include<iostream>

using namespace std;

class node{
public:
	int data;
	node* next;
	node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void insertAtHead(node*& head,int data){
	node* n1 = new node(data);
	n1->next = head;
	head = n1;
}

void printLL(node* head){
	while(head->next != NULL){
		cout << head->data;
		head = head->next;
	}
}

int main(){
	
}
