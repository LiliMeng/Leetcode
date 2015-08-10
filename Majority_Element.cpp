class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int res = nums[0];
        int count = 1;
        int size = nums.size();
        //vote from the second number
        for( int i = 1; i < size; i++ )
        {
            if( count == 0 ) 
            {
                res = nums[i]; count++;
            }
            else if( res == nums[i] )
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return res;
    }
};
