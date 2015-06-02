#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size()<=1)
        {
            return 0;
        }

        int minProfit=prices[0];

        int profit = prices[1]-prices[0];

        for(int i=2;i<prices.size();i++)
        {
            minProfit=min(prices[i-1],minProfit);
            profit=max(profit,prices[i]-minProfit);
        }

        if(profit<0)
        {
            return 0;
        }
        return profit;
    }
};


int main(){

    Solution s;
    vector<int> prices={1,2,3,6};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}
