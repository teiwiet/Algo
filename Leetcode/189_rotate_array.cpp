#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums,int k) {
		int n = nums.size();
		k = n-k;
		reverse(nums,0,k-1);
		reverse(nums,k,n-1);
		reverse(nums,0,n-1);
   }
	
	void reverse(vector<int>& a,int low,int high){
		while(low < high){
			swap(a[low],a[high]);
			low++;
			high--;
		}
	}
	void swap(int& a,int& b){
		int temp = a;
		a = b;
		b = temp;
	}
};

void inputArr(vector<int>& a,int n){
	a.resize(n);
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
}

void outputArr(vector<int>& a,int n){
	for(int nums : a){
		cout << nums << " " ;
	}
	cout << endl;
}
int main(){
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> a;
	inputArr(a,n);
	Solution* sol = new Solution();
	sol->rotate(a,k);
	outputArr(a,n);
}
