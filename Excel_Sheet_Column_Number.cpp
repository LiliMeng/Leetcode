class Solution {
public:
    int titleToNumber(string s) {
        
        int n=s.length();
        int memory[n];

        int result=0;

        for(int i=0; i<n; i++)
        {
             memory[i]=s[i]-'A'+1;
        }


        for(int i=0; i<n; i++)
        {
            result=result+memory[i]*pow(26,n-1-i);
        }

        return result;
    }
};
