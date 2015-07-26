//Caution: as it's using unordered_map which has no orders, so the i and htable[num2] must be compared so that index1 is smaller than index2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> htable;
        
        for(int i=0; i<nums.size();i++)
        {
            htable.insert({nums[i],i});
        }
        
        vector<int> result;
        
        for(int i=0; i<nums.size();i++)
        {
            int num2=target-nums[i];
            if(htable.find(num2)!=htable.end())
            {
                if(i<htable[num2])
                {
                    result.push_back(i+1);
                    result.push_back(htable[num2]+1);
                    break;
                }
                else if(i>htable[num2])
                {
                    result.push_back(htable[num2]+1);
                    result.push_back(i+1);
                    break;
                }
            }
        }
        return result;
    }
};
