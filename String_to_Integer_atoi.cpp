class Solution {
public:
    int myAtoi(string str) {
         
        if(str.empty())  
        {  
            return 0;  
        }  
  
        int i = 0;  
        
        while(str[i] == ' ')  
        {  
            i++;  
        }  
  
        int sign = 1;  
        
        if(str[i] == '-')  
        {  
            sign = -1;  
            i++;  
        }  
        else if(str[i] == '+')  
        {  
            i++;  
        }  
  
        long res = 0;  
        while(!str.empty())  
        {  
            if(str[i] >= '0' && str[i] <= '9')  
            {  
                res = res * 10 + (str[i] - '0');  
  
                if(res > INT_MAX)  
                {  
                    if(sign == -1)
                    return INT_MIN;
                    else 
                    return INT_MAX;  
                }  
            }  
            else  
            {  
                break;  
            }  
  
            i++;  
        }  
  
        return sign * res;  
    }
};
