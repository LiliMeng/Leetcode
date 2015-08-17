class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        unordered_map<int, int> htable;
        
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
                return nums[i];
            }
        }
    }
};
