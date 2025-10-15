#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void my_swap(T& a,T& b){
    int temp = a;
    a = b;
    b = temp;
}
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(right > left){
            my_swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};

int main(){
    vector<char> s;
}