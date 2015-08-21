class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
            else
            {
                if(target<nums[0])
                {
                    return 0;
                }
                else if(target>nums[nums.size()-1])
                {
                    return nums.size();
                }
                else if(target>nums[i]&&target<nums[i+1])
                {
                    return i+1;
                }
            }
        }
    }
};

//Binary Search Complexity log(n)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int start=0;
        int end=nums.size()-1;
        
        if(target<nums[0])
        {
            return 0;
        }
        if(target>nums[nums.size()-1])
        {
            return nums.size();
        }
        
        while(start<end)
        {
            int mid=(start+end)/2;
            
            if(nums[mid]>target&&nums[mid-1]<target) return mid;
            
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
                return mid;
            }
            
        }
    }
};
