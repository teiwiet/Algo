#include<iostream>
using namespace std;

int binary_search(int arr[],int key,int n){
	int s = 0 ;
	int e = n-1;
	while(s<=e)
	{
		int mid = (s+e)/2;
		if(arr[mid] == key)
		{
			return mid;
		}
		else if(arr[mid]> key)
		{
			e = mid-1;	
		}
		else
		{
			s = mid+1;
		}

	}
	return -1;
}


int main(){
	int arr[] = {1,2,3,4,5,6,7};
	cout << binary_search(arr,2,6) << "\n";
	return 0;
}
