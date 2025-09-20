#include<iostream>
using namespace std;

void read_line(char a[],int maxLen,char delim = '\n'){
	int i = 0;
#char ch = cin.get();
	while(ch!=delim){
		a[i] = ch;
		i++;
		if(i==maxLen-1){
			break;
		}
		ch = cin.get();
	}
	a[i] = '\0';
	return;
}


int main(){
	char a[1000];
	int maxLen = 1000;
	read_line(a,maxLen,'\n');
	cout << a << endl;
	return 0;
}
