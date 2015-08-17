class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     
        int n=nums.size();
        
        vector<int> res(n,1);
        for(int i=1; i<n; i++)
        {
            res[i]=res[i-1]*nums[i-1];
        }
        for(int i=n-1, r=1; i>=0; r*=nums[i--])
        {
            res[i]=res[i]*r;
        }
        
        return res;
    }
};
