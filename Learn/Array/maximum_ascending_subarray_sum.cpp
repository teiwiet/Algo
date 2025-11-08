#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums){
        int sum = nums[0];
        int currSum = nums[0];
        for(int i = 1;i<nums.size();i++){
            cout << "Sum" << sum << endl;
            cout << "currSum : " << currSum << endl;
            if(nums[i-1]>=nums[i]){
                currSum = nums[i];
            }
            else{
                currSum += nums[i];
            }
            sum = max(sum,currSum);
        }
        return sum;
    }
};

int main(){
    Solution *s = new Solution();
    vector<int> nums {3,6,10,1,8,9,9,8,9};
    cout << s->maxAscendingSum(nums);
}

