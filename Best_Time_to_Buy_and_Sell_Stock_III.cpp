#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size()<=1)
        {
            return 0;
        }

        vector<int> profitVec;
        profitVec.resize(prices.size());

        int minPrice1=prices[0];
        int profit1=numeric_limits<int>::min();

        int maxPrice2=prices[prices.size()-1];
        int profit2=numeric_limits<int>::min();

        for(int i=1; i<prices.size();i++)
        {
            minPrice1=min(prices[i-1],minPrice1);
            profitVec[i]=max(profit1,prices[i]-minPrice1);
            profit1=profitVec[i];
        }

        for(int i=prices.size()-2;i>0;i--)
        {
            maxPrice2=max(prices[i+1],maxPrice2);
            profit2=max(profit2,maxPrice2-prices[i]);

            if(profit2>0)
            {
                profitVec[i]=profitVec[i]+profit2;
                profit1=max(profit1,profitVec[i]);
            }
        }

        return profit1>0?profit1:0;

    }
};



int main(){

    Solution s;
    vector<int> prices={1,2,4,2,5,7,2,4,9,0,9};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}
