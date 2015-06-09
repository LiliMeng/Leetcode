#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

    if(grid.empty()||grid[0].empty()) return 0;
    int m=grid.size();
    int n=grid[0].size();

    int dp[m][n];
    dp[0][0]=grid[0][0];

    for(int i=1;i<m;i++)
    {
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int j=1;j<n;j++)
    {
        dp[0][j]=dp[0][j-1]+grid[0][j];
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(dp[i-1][j]<=dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j]+grid[i][j];
            }
            else
            {
                dp[i][j]=dp[i][j-1]+grid[i][j];
            }
        }
    }
    return dp[m-1][n-1];
    }
};



int main(){

    Solution s;
    vector<vector<int>> grid={{1,2,0},{0,4,0},{4,0,5}};
    cout<<s.minPathSum(grid)<<endl;
    return 0;
}
