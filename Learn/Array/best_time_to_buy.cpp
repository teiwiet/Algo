#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int> prices){
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1;i<prices.size();i++){
            if(minPrice > prices[i]){
                minPrice = prices[i];
            }
            else if (maxProfit<prices[i]-minPrice){
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};

int main(){
    Solution *s = new Solution();
    vector<int> prices {7,1,5,3,6,4};
    cout << s->maxProfit(prices);
}
