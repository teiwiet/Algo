#include<iostream>
using namespace std;

int binary_search(int a[],int n,int target){
	int s = 0;
	int e = n-1;
	for(int i=0;i<n;i++){
		int mid = (s+e)/2;
		if(a[mid] == target){
			return mid;
		}
		else if(a[mid]<target){
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	return -1;
}

void input_arr(int a[],int n){
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
}

void output_arr(int a[],int n){
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}
int main(){
	int a[100];
	int n;
	int target;
	cout << "number of elements : " ;
	cin >> n;
	cout << "array : ";
	input_arr(a,n);
	cout << "target : ";
	cin >> target;
	cout << binary_search(a,n,target);
	return 0;
}
