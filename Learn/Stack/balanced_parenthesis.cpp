#include<iostream>
#include<stack>
using namespace std;

bool matching(char a, char b){
	return (
			(a=='(' && b==')') || 
			(a=='{' && b=='}') ||
			(a=='[' && b==']')
			);	
}

bool isBalanced(string& str){
	stack<char> s;
	for(int i = 0;i<=str.length()-1;i++){
		if(str[i]=='(' || str[i]=='{' || str[i]=='['){
			s.push(str[i]);
		}
		else{
			if(s.empty()==true){
				return false;
			}
			if(matching(s.top(),str[i]) == false){
				return false;
			}
			else {
				s.pop();
			}
		}
	}
	return s.empty() == true;
}

int main(){
	string s;
	s = "({[]})";
	isBalanced(s) ? cout << "YES\n" : cout << "NO\n";
}
