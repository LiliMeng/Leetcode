class Solution {
public:
    int hammingWeight(uint32_t n) {
          
        int count = 0;  
        while (n)  
        {  
            count++;  
            n = (n - 1) & n;  
        }  
  
    return count;  
    }
};

// if n!=0, count++, and then n=(n-1)&n; if n is the power of 2, there is definitely one 1 digit. 

// if n is the power of 2, (n-1)&n=0, n=0, there is only one 1 digit; if n is not power of 2, and n!=0, (n-1)&n will be 1, and loop till n is the power of two, in that situation, there is only one 1 digit left
