class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry=0;
        
        vector<int> res;
        
        for(int i=digits.size()-1; i>=0; i--)
        {
            if(i==digits.size()-1)
            {
                digits[i]=digits[i]+1;
                
            }
            else
            {
                digits[i]=digits[i]+carry;
            }
            
            carry=digits[i]/10;
            
            digits[i]=digits[i]%10;
    
        }
        
        if(carry>0)
        {
            res.push_back(carry);
            for(int i=0; i<digits.size();i++)
            {
                res.push_back(digits[i]);
            }
        }
        else
        {
            for(int i=0; i<digits.size();i++)
            {
                res.push_back(digits[i]);
            }
        }
        return res;
        
    }
};
