//https://leetcode.com/problems/maximum-ascending-subarray-sum/
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxAscendingSum(vector<int> nums){
        int sum = nums[0];
        int currSum = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i] < nums[i+1]){
                currSum += nums[i+1];
            }
            else{
                currSum = nums[i+1];
            }
            sum = max(sum,currSum);
        }
        return sum;
    }
};


int main(){
    Solution *s = new Solution();
    vector<int> a {10,20,30,5,10,50};
    cout << s->maxAscendingSum(a);
}
