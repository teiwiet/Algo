#include<iostream>
#include<stack>

using namespace std;

class Solution{
public:
	string infixToPostfix(string& s){
		stack<char> stk;
		string res = "";
		for(char c : s){
			if(isalnum(c)){
				res+=c;
			}
			else{
				while(!stk.empty()){
					int currP = precendence(c);
					int topP = precendence(stk.top());
					if(topP > currP || (currP==topP && !isAssociated(c))){
						res+=stk.top();
						stk.pop();
					}
					else break;
				}
				stk.push(c);
			}
		}
		while(!stk.empty()){
			res+=stk.top();
			stk.pop();
		}
		return res;
	}
	
	int precendence(char c){
		if(c=='^') return 3;
		if(c=='*' || c == '/') return 2;
		if(c=='+' || c == '-') return 1;
		return -1;
	}
	
	bool isAssociated(char c){
		return c=='^';
	}
};

int main(){
	string s;
	cin >> s;
	Solution *so = new Solution();
	cout << so->infixToPostfix(s) << endl;
};
