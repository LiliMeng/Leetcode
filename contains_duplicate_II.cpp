class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> htable;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(htable.find(nums[i])==htable.end())
            {
                htable[nums[i]]=i;
            }
            else
            {
                //if the value has occurred before, check the difference
                if(i-htable[nums[i]]<=k)
                {
                    return true;
                }
            //update the index of the value
            htable[nums[i]]=i;
            }
        }
        return false;
    }
};
