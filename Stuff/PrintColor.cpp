#include<iostream>

using namespace std;
void print_red(char* s){
	cout << "\e[31m" << s << "\e[0m\n";
}
int main(){
	char s[] = "something";
	print_red(s);
	return 0;
}
