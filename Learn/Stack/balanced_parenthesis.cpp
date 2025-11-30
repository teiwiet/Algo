#include<iostream>
#include<stack>
using namespace std;

class Solution{
public:
	bool isMatching(char a, char b){
		return (
			(a=='(' && b==')') ||
			(a=='[' && b==']') ||
			(a=='{' && b=='}') 
		)
	}
	bool isValid(string s){
		stack<char> st;
		for(char c:s){
			if(c=='(' || c=='{' || c=='['){
				st.push(c);
			}
			else{
				if(st.empty()){
					return false;
				}
				if(isMatching(st.top(),c) == false){
					return false;
				}
				else {
					st.pop();
				}
			}
		}
		return st.empty();
	}
};

int main(){

}
