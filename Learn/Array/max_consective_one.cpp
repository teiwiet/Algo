#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsectiveOnes(vector<int> nums){
        int count = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count = 0;
            }
            else{
                count++;
                res = max(count,res);
            }
        }
        return res;
    }
};


int main(){
    Solution *s = new Solution();
    vector<int> nums {1,1,0,1,1,1};
    cout << s->findMaxConsectiveOnes(nums);
}

