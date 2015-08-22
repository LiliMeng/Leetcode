#include<iostream>
#include<vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res;
        int n=nums.size()-1;

        int index=searchTarget(nums,0,n-1,target);

        if(index==-1)
        {
            res.push_back(-1);
            res.push_back(-1);
        }
        else
        {
            int i=index;
            while(i>0 && nums[i-1]==nums[index])
            {
                i--;
            }
            int j=index;
            while(j<n-1 && nums[j+1]==nums[index])
            {
                j++;
            }

        }

        return res;
    }

    int searchTarget(vector<int>& nums, int start, int end, int target)
    {
        if(start>end)
        {
            return -1;
        }

        int mid=start+(end-start)/2;

        if(nums[mid]<target)
        {
            return searchTarget(nums, mid+1, end, target);
        }
        else if(nums[mid]>target)
        {
            return searchTarget(nums, start, mid-1, target);
        }
        else
        {
            return mid;
        }

    }

};

int main()
{
    Solution s;
    vector<int> nums={1,4,5,6,8,8,8,10};
   // vector<int> res;
    int res=s.searchTarget(nums,0, nums.size()-1, 8);
    cout<<res<<endl;
/*
    for(auto ite=nums.begin(); ite!=nums.end(); ite++)
    {
        cout<<*ite<<endl;
    }
*/
}
