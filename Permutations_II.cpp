#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> allPermu;
        vector<int> currPermu;
        vector<bool> isVisited(nums.size(),false);
        backtracking(allPermu,currPermu,nums,isVisited);
        return allPermu;
    }

    void backtracking(vector<vector<int>>& allPermu, vector<int>& currPermu, vector<int>& nums,vector<bool> isVisited)
    {
        if(currPermu.size()==nums.size())
        {
            allPermu.push_back(currPermu);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(isVisited[i]==false)
            {
                isVisited[i]=true;
                currPermu.push_back(nums[i]);
                backtracking(allPermu,currPermu,nums,isVisited);
                currPermu.pop_back();
                isVisited[i]=false;
                while(i < nums.size()-1 && nums[i] == nums[i+1]) //use this while loop to skip the duplication value in the input array.
                    ++i;
            }
        }
    }
};

int main()
{
    vector<vector<int>> allPermu;
    vector<int> nums={1,1,3};
    Solution s;
    allPermu=s.permuteUnique(nums);
    for(auto ite=allPermu.begin();ite!=allPermu.end();ite++)
    {
        vector<int> currPermu=*ite;
        for(auto ite2=currPermu.begin();ite2!=currPermu.end();ite2++)
        {
            cout<<*ite2;
        }
        cout<<"*********************"<<endl;
    }
}
