#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums,int l,int h,int target){
    if(l>h) return -1;
    int mid = (l+h)/2;
    if(nums[mid] == target){
        return mid;
    }
    else if(nums[mid] > target){
        return binarySearch(nums,l,mid-1,target);
    }
    else{
        return binarySearch(nums,mid+1,h,target);
    }
}

int main(){
    vector<int> nums {1,2,3,4,5,6};
    cout << binarySearch(nums,0,nums.size(),6);
}
