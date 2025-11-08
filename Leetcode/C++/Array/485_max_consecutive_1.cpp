#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        for(int i = 0;i<nums.size();i++){
            int curr;
            if(nums[i]==0){
                curr = 0;
            }
            else{
                curr++;
                res = max(curr,res);
            }
        }
        return res;
    }
};



int main(){

}
