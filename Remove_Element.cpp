//这里不能用erase() 因为是in place
//The order of elements can be changed. It doesn't matter what you leave beyond the new length
//把val的值移动到最后面 比如{1,2,3,4,3,5,3,6} 移动成{1,2,4,5,6,3,3,3}所以后面怎么样没关系的 数组最重要的是下标
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int cur=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==val)
            {
                continue;
            }
            nums[cur]=nums[i];
            cur++;
        }
        
        return cur;
    }
};
