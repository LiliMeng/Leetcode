class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> res;
        unordered_map<int, int> htable;
        
        if(nums.size()==0) return res;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(htable.find(nums[i])==htable.end())
            {
                htable.insert({nums[i],1});
            }
            else
            {
                htable[nums[i]]+=1;
            }
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(htable[nums[i]]==1)
            {
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
};
