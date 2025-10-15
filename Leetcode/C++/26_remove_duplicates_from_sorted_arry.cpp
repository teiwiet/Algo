#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int res = 1;
	for(int i = 1;i<nums.size();i++){
		if(nums[i] != nums[i-1]){
			nums[res] = nums[i];
			res++;
		}
	}
	return res;
   
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
}

int main(){
	int n;
	cin >> n;
	vector<int> a;
	inputArr(a,n);
	outputArr(a,n);
	Solution* sol = new Solution();
	sol->removeDuplicates(a);
}
