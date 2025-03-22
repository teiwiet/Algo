#include<iostream>
using namespace std;
int binary_search(int a[],int n,int key){
	int s = 0;
	int e = n-1;
	while(s<=e){
		int mid = (s+e)/2;
		if(a[mid] == key){
			return mid+1;
		}
		else if(a[mid]>key){
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	return -1;
}

int main(){
	int a[100];
	int n; 
	cout << "Numbers of elements : ";
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int key;
	cout << "Key : ";
	cin >> key;
	cout <<	binary_search(a,n,key) << endl;
	return 0;
}
