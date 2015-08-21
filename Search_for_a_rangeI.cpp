class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
       vector<int> res;
       res.push_back(findleft(nums,target));
       res.push_back(findright(nums,target));
       return res;
    } 
    
    int findleft(vector<int>& nums, int target)
    {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]<target)
            {
                start=mid+1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                end=mid-1;
            }
        }
        
        if(nums[start]==target)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
    
    int findright(vector<int>& nums, int target)
    {
        int start =0;
        int end=nums.size()-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]<target)
            {
                start=mid+1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        
        if(nums[end]==target)
        {
            return end;
        }
        else
        {
            return -1;
        }
    }
};
