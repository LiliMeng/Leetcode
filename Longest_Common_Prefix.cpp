class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string res;
        if(strs.size()==0) return res;
        
        for(int i=0; i<strs[0].size(); i++)  ////最长前缀的长度不超过strs[0].size()，逐个字符的比较
        {
           for(int j=1; j<strs.size(); j++) 
           {
               if(strs[j].size()==i||strs[j][i]!=strs[0][i])  //strs[0]的第i个字符分别和strs[1...n-1]的第i个字符比较
               {
                   return res;
               }
           }
           res.push_back(strs[0][i]);
        }
        return res;
    }
};
