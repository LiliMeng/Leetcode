public:
    int calculate(string s) {
        stack<char> signs;
        signs.push(1);
        int sign=1;
        int ans=0;
        int num=0;
        for(char c : s)
        {
            if(c>='0' && c<='9')
            {
                num=num*10+c-'0';
            }
            else if(c=='+' || c=='-')
            {
                ans=ans+signs.top()*sign*num;
                num=0;
                sign=c=='+'?1:-1;
            }
            else if(c=='(')
            {
                signs.push(signs.top()*sign);
                sign=1;
            }
            else if(c==')')
            {
                ans=ans+signs.top()*sign*num;
                signs.pop();
                sign=1;
                num=0;
            }
            
        }
        
        if(num)
        {
            ans=ans+signs.top()*sign*num;
        }
        
        return ans;
    }
};
