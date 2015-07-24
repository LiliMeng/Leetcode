class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> htable;
        
        for(int i=0; i<nums.size();i++)
        {
            htable.insert({nums[i],1});
        }
        
        if(htable.size()==nums.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
