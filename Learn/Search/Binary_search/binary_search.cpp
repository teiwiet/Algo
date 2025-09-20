#include<iostream>
using namespace std;
int binary_search(int a[],int n,int x){
	int low = 0,high = n-1;
	while(low <= high){
	int mid = (low+high)/2;
		if(mid == x){
			return mid ;
		}
		else if(mid < x){
			high = mid - 1;
		}
		else if(mid > x){
			low = mid + 1;
		}
	}
	return -1;
}

void inputArr(int a[],int n){
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
}
void outputArr(int a[],int n){
	for(int i = 0;i < n;i++){
		cout << a[i] << " ";
	}
}
int main(){
	int n,a[100];
	cin >> n;
	inputArr(a,n);
	outputArr(a,n);
	cout << binary_search(a,n,4);
}
