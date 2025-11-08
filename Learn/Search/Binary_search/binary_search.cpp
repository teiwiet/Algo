#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums,int target){
    int low = 0;
    int high = nums.size();
    while(low<high){
        int mid = (low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid] < target){
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
}


int main(){
    vector<int> nums {10,20,30,40,50,60};
    cout << binarySearch(nums, 50);
}
