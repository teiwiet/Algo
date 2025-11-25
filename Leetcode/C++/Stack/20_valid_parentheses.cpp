//https://leetcode.com/problems/valid-parentheses/#include<iostream>
#include<vector>
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	bool isMatching(char a, char b){
	return (
			(a=='(' && b==')') || 
			(a=='{' && b=='}') ||
			(a=='[' && b==']')
			);	
	}
	bool isValid(string s){
		stack<char> stk;
		for(int i = 0;i<= s.length()-1;i++){
			if(s[i]=='(' || s[i]=='{' || s[i]=='['){
				stk.push(s[i]);
			}
			else{
				if(stk.empty() == true){
					return false;
				}
				if(isMatching(stk.top(),s[i]) == false){
					return false;
				}
				else {
					stk.pop();
				}
			}
		}
		return stk.empty() == true;
	}
};


int main(){
    Solution *s = new Solution();
	string str;
	str = "([{}])";
	cout << s->isValid(str);
}


