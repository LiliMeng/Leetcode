class Solution {
public:
    string multiply(string num1, string num2) {
        
        string res(num1.size()+num2.size(), '0');
        
        for(int i=num1.size()-1, d=res.size()-1; i>=0; i--, d--)
        {
            int carry=0, k=d;
            
            for(int j=num2.length()-1; j>=0; j--, k--)
            {
                int a=num1[i]-'0';
                int b=num2[j]-'0';
                a=a*b+carry+(res[k]-'0');
                carry=a/10;
                res[k]=a%10 + '0';
            }
            
            while(carry!=0)
            {
                int sum=carry+(res[k]-'0');
                carry=sum/10;
                res[k--]=sum%10+'0';
            }
        }
        
        while(res.size()>1&&res[0]=='0') res.erase(res.begin());
        
        return res;
        
    }
};
