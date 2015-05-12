#include <iostream>
#include <vector>

using namespace std;

/*For this peak finding, the tricky part is

if(nums[0]>nums[1])  return 0; 
if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1; 
under the assumption that (nums[i]>nums[i+1] and nums[i]>nums[i-1]) could not be satisfied. */


class Solution {
public:

    int findPeakElement(vector<int>& nums) {

    for(int i=0; i<nums.size();i++)
    {

        if(nums[i]>nums[i+1] and nums[i]>nums[i-1])
        return i;
        else if(nums[0]>nums[1])
        return 0;
        else if(nums[nums.size()-1]>nums[nums.size()-2])
        return nums.size()-1;

    }

    }
};


int main(){

    vector<int> v={1,2,3,4,5,3,2};
    Solution s;
    cout<<s.findPeakElement(v);
    return 0;
}
