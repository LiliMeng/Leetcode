//IV代表4 (V-I=5-1=4)   VI代表6(V+I=5+1=6)
class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<int, int> htable;
        htable.insert({'I'-'A',1});
        htable.insert({'V'-'A',5});
        htable.insert({'X'-'A',10});
        htable.insert({'L'-'A',50});
        htable.insert({'C'-'A',100});
        htable.insert({'D'-'A',500});
        htable.insert({'M'-'A',1000});
        int res=0;
        int n=s.size();
        s.push_back(s[n-1]);
        
        for(int i=0; i<n; i++)
        {
            if(htable[s[i]-'A']>=htable[s[i+1]-'A'])
            {
                res=res+htable[s[i]-'A'];
            }
            else
            {
                res-=htable[s[i]-'A'];
            }
        }
       
       return res;
        
    }
};
