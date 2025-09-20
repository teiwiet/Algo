#include<iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int search(vector<int>& nums,int target){
		int s = 0;
		int e = nums.size()-1;
		while(s<=e){
			int mid = (s+e)/2;

			if(nums[mid] == target){
				return mid;
			}
			else if(nums[mid]>target){
				e = mid-1;
			}
			else{
				s = mid+1;
			}
		}
		return -1;
	}
};

int main(){
	vector<int> v = {1,3,4,6,8,9};
	int target = 8;
	Solution* s1 = new Solution();
	cout << s1->search(v,target);
}
