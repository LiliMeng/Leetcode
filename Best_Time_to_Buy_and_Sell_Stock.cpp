#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size()<1)
        {
            return 0;
        }

        int minPrice=prices[0];
        int maxProfit=prices[1]-prices[0];

        for(int i=1;i<prices.size();i++)
        {
            minPrice=min(prices[i-1],minPrice);

            maxProfit=max(maxProfit,prices[i]-minPrice);
        }

        if(maxProfit<0)
        {
            return 0;
        }
        return maxProfit;
    }
};


int main(){

    Solution s;
    vector<int> prices={6,1,3,2,4,7};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}
