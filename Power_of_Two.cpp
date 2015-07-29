class Solution {
public:
    bool isPowerOfTwo(int n) {
     
     if(n>0)
     {
         return !(n&(n-1));
         
     }
     else
     {
         return false;
     }
     
    }
};

// If a number n is the power of 2, if written in binary format, the first digit shall be 1, such as (10000,10,1,100, or sth)

//n-1 shall be 11111 or numbers of all 1, For this case n&(n-1) must be 0; !(n&(n-1)) must be 1 

//If a number n is not the power of 2, and written in binary format, n&(n-1) will be 1, as the first digit of n will be 1 and the first digit of n-1 will be 1
