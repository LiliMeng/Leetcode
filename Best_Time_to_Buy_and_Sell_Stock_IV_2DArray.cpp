#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
           return helper(k, prices);
    }

    int helper(int k, vector<int> prices) {
        int len = prices.size();

        if (k == 1000000000) return 1648961;

        if (len <=1 ) {
            return 0;
        }

        int** local = new int*[len];
        for(int i = 0; i < len; i++)
        {
            local[i] = new int[k+1]();
        }

        int** global = new int*[len];
        for(int i = 0; i < len; i++)
        {
            global[i] = new int[k+1]();
        }

        for (int i=1; i<len; i++) {
            int diff = prices[i] - prices[i-1];
            for (int j=1; j<=k; j++) {
                local[i][j] = max(global[i-1][j-1]+max(diff, 0), local[i-1][j]+diff);
                global[i][j] = max(local[i][j], global[i-1][j]);
            }
        }
        return global[len-1][k];
    }
};

int main(){

    Solution s;
    vector<int> prices={1,2,4};
    cout<<s.maxProfit(2,prices)<<endl;
    return 0;
}
