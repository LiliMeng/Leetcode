class Solution {
public:
    string multiply(string num1, string num2) {
        
       if(num1.empty() || num2.empty())
            return "";
        int s1 = num1.size();
        int s2 = num2.size();
        string ret(s1+s2, '0');
        int i, j;
        for(i=s1-1; i>=0; --i){
            int carry = 0;
            for(j=s2-1; j>=0; --j){
                int tmp = (ret[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry;
                ret[i+j+1] = '0'+tmp%10;
                carry = tmp/10;
            }
            ret[i]+=carry;
        }
        //skip the leading 0's
        for(i=0; i<s1+s2; ++i){
            if(ret[i]!='0')
                return ret.substr(i, s1+s2-i);
        }
        return "0";
    }
};
