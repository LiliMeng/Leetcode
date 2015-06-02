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

        int profitSum=0;

        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]>prices[i])
            {
                 profitSum=profitSum+prices[i+1]-prices[i];
            }
        }

        return profitSum;
    }
};


int main(){

    Solution s;
    vector<int> prices={1,2};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}
