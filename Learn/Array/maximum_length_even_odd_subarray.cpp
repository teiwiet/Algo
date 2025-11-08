#include<iostream>
#include<vector>
using namespace std;

int maxEvenOdd(vector<int>& nums,int threshold){
    int res = 0;
    int curr = 0;
    for(int i = 1;i<nums.size();i++){
        cout << "Sum : " << res << "currSum : " << curr << endl;
        if((nums[i]%2==0&&nums[i+1]%2!=0 || nums[i]%2!=0&&nums[i+1]%2==0) && nums[i]<=threshold){
            curr++;
            res = max(res,curr);
        }
        else{
            curr=1;
        }
    }
    return res;
}

int main(){
    vector<int> nums {3,2,5,4};
    cout << maxEvenOdd(nums,5);
}
