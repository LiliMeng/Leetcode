class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp(n+1,0);
        
        dp[0]=1;   //左树为NULL
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                dp[i]=dp[i]+dp[j]*dp[i-j-1];   //dp[j]是左边树的个数， dp[i-j-1]是右边树有的可能性
            }
        }
        
        return dp[n];
    }
};

//Three tree Nodes:
// dp[3]=dp[3]+dp[0]*dp[2]  以3为root, 左树有0个node 即左树为NULL, 右边树有2个node 的情况 最初dp[3]=0 更新后dp[3]=2
// dp[3]=dp[3]+dp[1]*dp[2] 以3为root, 左树有1个node, 右树有1个node的情况  更新后dp[3]=3;
// dp[3]=dp[3]+dp[2]*dp[1] 以3为root, 左树有2个node, 右树有0个node的情况  更新后dp[3]=5;
// 当i=4时
// for(int j=0; j<4; j++)
// {
//    dp[4]=dp[4]+dp[j]*dp[4-j-1]; 之所以减一是因为有root
// }
