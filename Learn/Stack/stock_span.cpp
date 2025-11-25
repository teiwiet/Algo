#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void span(vector<int> arr){
	stack<int> stk;
	stk.push(0);
	cout << 1 << " ";
	for(int i = 1;i<=arr.size()-1;i++){
		while(stk.empty()==false && arr[stk.top()] <= arr[i]){
			stk.pop();
		}
		int span = stk.empty() ? i+1:i-stk.top();
		cout << span << " ";
		stk.push(i);
	}
	cout << endl;
}


int main(){
	vector<int> arr {60,10,20,40,35,30,50,70,65};
	span(arr);
}
