#include<iostream>
#include<vector>
using namespace std;

class Solution{
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;    
        int min_price = INT_MAX;
        for(int i = 0;i<prices.size();i++){
            if(prices[i] < min_price){
                min_price = prices[i];
            }
            else if(max_profit < prices[i]-min_price){
                max_profit = prices[i]-min_price;
            }
        }
        return max_profit;
    }
};

int main(){

}
