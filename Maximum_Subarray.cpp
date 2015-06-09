#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;



class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int m = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            m = max(m, sum);

            if(sum < 0) {
                sum = 0;
            }
        }

        return m;

    }
};

int main(){

    vector<int> nums={ 1,4,-6,5};
    Solution s;
    cout<<s.maxSubArray(nums)<<endl;
}
