class Solution {
public:
    int lengthOfLastWord(string s) {
        
        if(s.length()==0)
        {
            return 0;
        }
        
        int count=0;
        
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i]!=' ')
            {
                count++;
            }
            if(s[i]==' '&&count!=0)
            {
                return count;
            }
        }
     
        return count;  
    }
};
