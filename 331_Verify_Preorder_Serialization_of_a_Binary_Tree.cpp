class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        if(preorder.empty()) 
        {
            return false;
        }
        
        istringstream in(preorder);
        vector<string> v;
        string val;
        int d = 0;
        
        while(getline(in,val,','))
        {
            v.push_back(val);
        }
        
        for(int i=0; i<v.size()-1; i++)
        {
            if(v[i]=="#")
            {
                if(d==0)
                {
                    return false;
                }
                else
                {
                    d--;
                }
            }
            else
            {
                d++;
            }
            
        }
        
        return d!=0?false : v.back()=="#";
      
    }
};
