class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        
        vector<string> res;
        if(strs.size()<=1) return res;
        unordered_map<string, int> htable;
        for(int i=0; i<strs.size(); i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            if(htable.find(s)==htable.end())
            {
                htable.insert({s,i});
            }
            else
            {
                if(htable[s]>=0)
                {
                    res.push_back(strs[htable[s]]);
                    htable[s]=-1;
                }
                res.push_back(strs[i]);
            }
        }
        
        return res;
    }
};
