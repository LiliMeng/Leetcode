class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> htable;
        
        vector<int> res;
        set<int> tmp;
        
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
            
            if(htable[nums[i]]>nums.size()/3)
            {
               tmp.insert({nums[i]});
            }
            
        }
        
        for(auto ite=tmp.begin(); ite!=tmp.end(); ite++)
        {
            res.push_back(*ite);   
        }
       
        return res;
    }
};
