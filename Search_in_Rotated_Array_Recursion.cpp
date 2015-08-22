class Solution {
public:
    int search(vector<int>& nums, int target) {
    
    int start=0;
    int end=nums.size()-1;

    return searchTarget(nums,start, end,  target);

}

    int searchTarget(vector<int>& nums, int start, int end, int target)
    {
        if(start>end)
        {
            return -1;
        }

        int mid=(start+end)/2;

        if(nums[mid]==target)
        {
            return mid;
        }

        if(nums[start]<=nums[mid])
        {
            if(target>=nums[start]&&target<=nums[mid])
            {
                return searchTarget(nums, start, mid-1, target);
            }
            else
            {
                return searchTarget(nums, mid+1, end, target);
            }
        }

       if(nums[mid]<=nums[end])
       {
            if(target>=nums[mid]&&target<=nums[end])
            {
                return searchTarget(nums, mid+1, end, target);
            }
            else
            {
                return searchTarget(nums, start, mid-1, target);
            }
       }

    }
};
