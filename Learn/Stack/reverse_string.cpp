#include<iostream>
#include<stack>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >>s;
		stack<char> stk;
		for(char c : s){
			stk.push(c);
		}
		while(stk.empty()!=true){
			cout << stk.top();
			stk.pop();
		}
		cout << endl;
	}
}
