#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int count = 0;
		for(int i = 0;i<nums.size();i++){
			if(nums[i]!=0){
				swap(nums[count],nums[i]);
				count++;
			}
		}
   }

	void swap(int &a,int &b){
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
	for(int i = 0;i<n;i++){
		cout <<  a[i] << " ";
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	vector<int> a;
	inputArr(a,n);
	Solution* sol = new Solution();
	sol->moveZeroes(a);
	outputArr(a,n);
	}
