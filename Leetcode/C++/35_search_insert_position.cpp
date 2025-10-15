#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int searchInsert(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size();
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] <=target){
                left = mid + 1;
            }
            else {
                right = mid-1;
            }
        }
        return left;
    }
};


int main(){
    Solution* s = new Solution();
    int n;
    cin >> n;
    vector<int> arr(n);
    int target;
    cin >> target;
    cout << s->searchInsert(arr,target);
}
