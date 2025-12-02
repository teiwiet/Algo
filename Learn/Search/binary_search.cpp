#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int search(vector<int>& nums,int target){
		int l = 0;
		int r = nums.size()-1;

		while(l<=r){
			int mid = (l+r)/2;
			if(nums[mid]==target){
				return mid;
			}
			else if(nums[mid]>target){
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		return -1;
	}
};


int main(){
	vector<int> nums {-1,0,3,5,9,12};
	Solution* s = new Solution();
	int target;
	cin >> target;
	cout << s->search(nums,target) << endl;
}
