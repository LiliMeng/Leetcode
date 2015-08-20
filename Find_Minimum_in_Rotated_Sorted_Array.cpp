class Solution {
public:
    int findMin(vector<int>& nums) {

        int start =0;
        int end = nums.size()-1;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]<nums[end])   //if nums[mid]<nums[end], [mid, end] has already been sorted, so the minimum will be in [0, mid], that is to say end=mid.
            {
                end = mid;
            }
            else
            {
                start = mid+1; //if nums[mid]>=nums[end], [mid, end] is not sorted, so the minimum will be in [mid+1, end], start=mid+1 
            }
        }
        
        return nums[start];
    }
};
