http://www.cnblogs.com/grandyang/p/4305572.html
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
       vector<string> res;
       restore(s,4,"",res);
       return res;
        
    }
    
    void restore(string s, int k, string remaining, vector<string> &res){   //remaining里面存的是已经搞定的部分, 分为4段,最初搞定的是空"""
        
        if(k==0)
        {
            if(s.empty()) 
            {
                res.push_back(remaining);
            }
        }
        else
        {
            for(int i=1; i<=3; i++)
            {
                if(s.size()>=i && isValid(s.substr(0,i)))
                {
                    if(k==1) 
                    {
                        if (s.substr(i).size() > 3) {   
                            break;
                        } //剪枝 如果发现当k==1时后面剩下的substr>3了 就完全不用进行 可以跳出了 
                        restore(s.substr(i), k-1, remaining+s.substr(0,i),  res);   //
                        
                    }
                    else
                    {
                        if (s.substr(i).size() > 3*k) {
                            break;
                        }
                        restore(s.substr(i), k-1, remaining+s.substr(0, i)+".", res);
                    }
            }
                
            }
        }
        
    }
  
    bool isValid(string s) {
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
        int res = atoi(s.c_str());
        return res <= 255 && res >= 0;
    }
};
