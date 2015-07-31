http://www.cnblogs.com/grandyang/p/4305572.html
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res;
        string current="";
        restore(current, s, 4, res);
        return res;
    }
private:
    void restore(string current, string remaining, int level, vector<string>& res)
    {
        if(level==0)
        {
            if(remaining.empty())
            {
                res.push_back(current);
            }
        }
        else
        {
            for(int i=1; i<=3; i++)
            {
    
                if(isValid(remaining.substr(0,i))&&remaining.size()>=i)
                {
                    string newCurrent;
                    if(level==1)
                    {
                        
                        newCurrent= current+remaining.substr(0,i);
            
                    }
                    else
                    {
                        newCurrent=current+remaining.substr(0,i)+".";
                    
                    }
                    restore(newCurrent, remaining.substr(i), level-1, res);
            
                }
            }
        }
    }

    bool isValid(string s)
    {
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
        int res = atoi(s.c_str());
        return res <= 255 && res >= 0;
    }
  
};
