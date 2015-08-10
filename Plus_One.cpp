class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry=0;
        
        vector<int> res(digits.size(), 0);
        
        for(int i=digits.size()-1; i>=0; i--)
        {
            if(i==digits.size()-1)
            {
                res[i]=digits[i]+1;
                
            }
            else
            {
                res[i]=digits[i]+carry;
            }
            
            carry=res[i]/10;
            
            res[i]=res[i]%10;
    
        }
        
        if(carry>0)
        {
            res.insert(res.begin(), carry);
        }
        
        return res;
    }
};
