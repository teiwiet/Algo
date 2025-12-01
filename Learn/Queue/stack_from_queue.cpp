#include<iostream>
#include<queue>

using namespace std; 

struct Stack{
	queue<int> q1,q2;
	int top(){

	}
	int pop(){

	}
	int size(){

	}

	void push(int x){
		while(!q1.empty()){
			q2.push(q1.top());
			q1.pop();
		}
		q1.push();

	}
};



int main(){

}
