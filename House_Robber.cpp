class Solution {
public:
    int rob(vector<int>& nums) {
     
     if(nums.size()==0) return 0;
     if(nums.size()==1) return nums[0];
     
     int n=nums.size();
     int dp[n];
     dp[0]=nums[0];
     dp[1]=nums[1];
     
     for(int i=2; i<n; i++)
     {
         dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
     }
     
     return max(dp[n-2],dp[n-1]);

    }
};
