class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> htable;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(htable.find(nums[i])==htable.end())
            {
                htable[nums[i]]=1;
            }
            else
            {
                htable[nums[i]]+=1;
            }
            
            if(htable[nums[i]]>nums.size()/2)
            {
                return nums[i];
            }
        }
        
        
    }
};
