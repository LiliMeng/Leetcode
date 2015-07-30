http://www.cnblogs.com/grandyang/p/4305572.html
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
       vector<string> res;
       restore(s,4,"",res);  //需要搞定4段, 现在已经搞定的string即已经分好的为"", res里面存的也是空, 每次搞定一段名叫remaining的string就放到res里
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
        {              //这里指k=1,2,3,4的情况 还没处理完4段
            for(int i=1; i<=3; i++)      //这里的i是指每一段
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
