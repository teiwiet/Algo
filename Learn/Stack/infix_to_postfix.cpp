#include<iostream>
#include<stack>

using namespace std;
class Solution{
public:
int precendence(char c){
	if(c=='^') return 3;
	if(c=='*' || c=='/') return 2;
	if(c=='+' || c=='-') return 1;
	return -1;
}

bool isAssociated(char c){
	return c=='^';
}
string infixToPostfix(string& s){
	stack<char> st;
	string res = "";
	for(char c:s){
		if(isalnum(c)){
			res+=c;
		}
		else if(c=='('){
			st.push(c);
		}
		else if(c==')'){
			while(!st.empty() && st.top()!='('){
				res+=st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty()){
				int topP = precendence(st.top());
				int currP = precendence(c);
				if(topP > currP || (topP==currP && !isAssociated(c))){
					res+=st.top();
					st.pop();
				}
				else break;
			}
			st.push(c);
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}

};

int main(){
	string s;
	cin >> s;
	Solution *so = new Solution();
	cout << so->infixToPostfix(s) << endl;
}
