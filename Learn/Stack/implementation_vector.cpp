#include<iostream>
#include<vector>
using namespace std;

struct MyStack{
	vector<int> arr;

	void push(int x){
		arr.push_back(x);
	}

	int pop(){
		int res = arr.back();
		arr.pop_back();
		return res;
	}

	int size(){
		return arr.size();
	}

	bool isEmpty(){
		return arr.empty();
	}

	int peek(){
		return arr.back();
	}
};


int main(){
	MyStack s;
	s.push(10);
	cout << s.peek();
}
