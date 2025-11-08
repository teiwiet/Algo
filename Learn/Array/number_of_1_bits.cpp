#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int hammingWeight(int n){
        int count = 0;
        for(int i = 0;i<32;i++){
            if((n>>i)&0x1){
                count++;
            }
        }
        return count;
    }
};


int main(){
    Solution *s = new Solution();
}

