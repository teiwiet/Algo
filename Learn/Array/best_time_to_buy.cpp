#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
		int min_price = prices[0];
		int max_profit = 0;
		for(int i = 0;i<prices.size();i++){
			if(prices[i]<min_price){
				min_price = prices[i];
			}
			if(max_profit < prices[i]-min_price){
				max_profit = prices[i] - min_price;
			}
		}
		return max_profit;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
	Solution *s = new Solution();
	cout << s->maxProfit(prices);
}
