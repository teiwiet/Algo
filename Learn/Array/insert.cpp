#include<iostream>
using namespace std;
void inputArr(int a[],int n){
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
}

void outputArr(int a[],int n){
	for(int i = 0;i<n;i++){
		cout << a[i] << " " ;
	}
	cout << endl;
}

void insertArr(int a[],int n,int x,int pos,int cap){
	if(n == cap){
		return;
	}

	int idx = pos-1;
	for(int i = n-1;i>=idx;i--){
		a[i] = a[i-1];
	}
	a[idx] = x;
}

int main(){
	int n;
	cin >> n;
	int a[100];
	inputArr(a,n);
	// insertArr(a,n,10,2,100);
	outputArr(a,n);
}
