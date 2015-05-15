#include<iostream>
#include<vector>

using namespace std;

void insertion_sort(vector<int>& nums){
	
	for(int i=1; i<nums.size();i++)
	{
		int k=i;
		while(k>=1)
		{
			if(nums[k]<nums[k-1])
			{	int temp=nums[k];
				nums[k]=nums[k-1];
				nums[k-1]=temp;
				k--;
			}
			else
				break;
			}
		}
	for(auto ite=nums.begin();ite!=nums.end();ite++)
	{
		cout<<*ite<<' ';
		}
}

int main()
{
	vector<int> nums={5,3,10,6};
	insertion_sort(nums);
	return 0;
	}
