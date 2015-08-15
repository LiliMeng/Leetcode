//这里不能用erase() 因为是in place
//The order of elements can be changed. It doesn't matter what you leave beyond the new length
//把val的值移动到最后面 比如{1,2,3,4,3,5,3,6} 移动成{1,2,4,5,6,3,3,3}所以后面怎么样没关系的 数组最重要的是下标
//这里用的vector<int>& 是reference 处理完这个函数后nums也变了. 如果要nums不变的话 需要用const vector<int>&
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int j=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=val)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        
        return j;
    }
};

int main()
{
    Solution s;
    vector<int> nums={1,2,3,4,5,3,3,4,3};
    int val=3;
    int l=s.removeElement(nums, val);
    //cout<<l<<endl;         //nums里面的数已经被改掉了,输出为1,2,4,5,4,3,3,4,3; nums这个vector最后四位没有变 仅仅是最初的3被4覆盖,nums[j]=nums[i](nums[2]=nums[3]) 4被5覆盖(nums[3]=nums[4]) 5后面那个3被最后的4覆盖(nums[4]=nums[7])
//然后后面那几位就不管了 因为nums[5]是3,nums[6]是3 nums[7](i=7)已经被提出去用来作为j=4的nums[4]了.
    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<endl;
    }
    return 0;
}

