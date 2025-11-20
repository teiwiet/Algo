#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int> prices){
		int max_profit = 0;
		for(int i = 0;i<prices.size();i++){
			if(prices[i]<prices[i+1]){
				max_profit += prices[i+1] - prices[i];
			}
		}
		return max_profit;
    }
};

int main(){
    Solution s;
    vector<int> prices {7,1,5,3,6,4};
    cout << s.maxProfit(prices);
}
