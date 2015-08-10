class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0) return 1;
        if(n==1) return x;
        
        double tmp=pow(x, abs(n/2));
        
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
