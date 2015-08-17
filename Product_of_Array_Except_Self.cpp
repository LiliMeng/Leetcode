//nums=[a1, a2, a3, a4]。
//res=[a2*a3*a4, a1*a3*a4, a1*a2*a4, a2*a3*a4]。
//find two array and multiply together
//[1, a1, a1*a2, a1*a2*a3]
//[a2*a3*a4, a3*a4, a4, 1]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     
        int n=nums.size();
        
        vector<int> res(n,1);
        vector<int> r(n,1);
        for(int i=1; i<n; i++)
        {
            res[i]=res[i-1]*nums[i-1];
        }
        
        for(int i=n-2; i>=0; i--)
        {
            r[i]=r[i+1]*nums[i+1];
        }
        
        for(int i=0; i<n; i++)
        {
            res[i]=res[i]*r[i];
        }
        return res;
    }
};

//算法2

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     
        int n=nums.size();
        
        vector<int> res(n,1);
        for(int i=1; i<n; i++)
        {
            res[i]=res[i-1]*nums[i-1];
        }
        for(int i=n-1, r=1; i>=0; r*=nums[i--])
        {
            res[i]=res[i]*r;
        }
        
        return res;
    }
};
