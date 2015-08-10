class Solution {
//分两种情况,一种n>0, 一种n<0的情况
class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0) return 1;
        if(n==1) return x;
        
        double tmp=pow(x, abs(n/2)); //为啥要abs(n/2)呢?
        
        if(n>0)
        {
            if(n&1)    
            {
                return tmp*tmp*x;
            }
            else
            {
                return tmp*tmp;
            }
        }
        else
        {
            if(n&1)
            {
                return 1.0/(tmp*tmp*x);
            }
            else
            {
                return 1.0/(tmp*tmp);
            }
        }
    }
};
