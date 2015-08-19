class Solution {
public:
    int calculate(string s) {
        
       int n = s.length();
        int num = 0;
        int lastNum = 0;
        int result = 0;
        int sign = 1;
        int op = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == ' ')
                continue;

            else if(s[i] >= '0' && s[i] <= '9') {
                num = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                if(op == 0)
                    lastNum = num;
                else if(op == 1)
                    lastNum *= num;
                else if(op == 2)
                    lastNum /= num;
            }

            else if(s[i] == '+') {
                result += sign * lastNum;
                sign = 1;
                op = 0;
            }

            else if(s[i] == '-') {
                result += sign * lastNum;
                sign = -1;
                op = 0;
            }

            else if(s[i] == '*') {
                op = 1;
            }

            else if(s[i] == '/')
                op = 2;
        }
        result += sign * lastNum;
        return result;
    }
};
