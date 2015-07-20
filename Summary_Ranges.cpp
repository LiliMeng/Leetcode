class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> res;
        int i=0, n=nums.size();
        
        while(i<n)
        {
            int j=1;
            while(i+j<n && nums[i+j] - nums[i]==j)
            j++;
            if(j<=1)
            {
                res.push_back(to_string(nums[i]));
            }
            else
            {
                res.push_back(to_string(nums[i])+"->"+to_string(nums[i+j-1]));
             }
             
             i=i+j;
        }
             
        return res;
        
    }
};
