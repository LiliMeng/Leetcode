#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if(nums.size()==0)
        {
            return 0;
        }

        if(nums.size()==1)
        {
            return nums[0];
        }

        int product=nums[0];
        int maxP=nums[0];
        int minP=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            int temp=maxP;
            maxP = max(max(maxP*nums[i],nums[i]),minP*nums[i]);
            minP = min(min(temp*nums[i],nums[i]),minP*nums[i]);
            product = max(maxP,product);

        }

        return product;
    }
};

int main(){

    Solution s;
    vector<int> nums={-4,-3};
    cout<<s.maxProduct(nums)<<endl;
    return 0;
}
