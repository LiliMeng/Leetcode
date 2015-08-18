class Solution {
public:
    int calculate(string s) {
        
        stack<char> signs;
        signs.push(1);
        int sign=1;
        int res=0;
        int num=0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                num=num*10+s[i]-'0';
            }
            else if(s[i]=='+'||s[i]=='-')
            {
                res=res+signs.top()*sign*num;
                num=0;
                if(s[i]=='+')
                {
                    sign=1;
                }
                else
                {
                    sign=-1;
                }
            }
            else if(s[i]=='(')
            {
                signs.push(signs.top()*sign);
                sign=1;
            }
            else if(s[i]==')')
            {
                res=res+signs.top()*sign*num;
                signs.pop();
                sign=1;
                num=0;
            }
        }
        
        if(num!=0)
        {
            res=res+signs.top()*sign*num;
        }
        
        return res;
    }
};
