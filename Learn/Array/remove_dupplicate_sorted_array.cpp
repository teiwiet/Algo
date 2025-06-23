#include<iostream>
#include<vector>
using namespace std;
void inputArr(int a[],int n){
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
}

void outputArr(int a[],int n){
	for(int i = 0;i<n;i++){
		cout << a[i] << " " ;
	}
	cout << endl;
}
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int res = 1;
		for(int i = 1;i<nums.size();i++){
			if(nums[i] != nums[i-1]){
				nums[res] = nums[i];
				res++;
			}
		}
		return res;
    }
};

int main(){
	int n;
	cin >> n;
	int a[100];
	inputArr(a,n);
	outputArr(a,n);

}
