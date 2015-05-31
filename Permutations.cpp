#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> allPermu;
    vector<int> currPermu;
    vector<bool> isVisited(nums.size(),false);
    backtracking(allPermu,currPermu,nums,isVisited);
    return allPermu;
    }

    void backtracking(vector<vector<int>> &allPermu, vector<int> &currPermu, vector<int> &nums, vector<bool> &isVisited)
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
            }
        }

    }
};

int main(){
    Solution s;
    vector<vector<int>> allPermu;
    vector<int> nums;
    nums={1,2,3};
    allPermu=s.permute(nums);
    for(auto ite=allPermu.begin();ite!=allPermu.end();ite++)
    {
        vector<int> currPermu=*ite;
        for(auto ite2=currPermu.begin();ite2!=currPermu.end();ite2++)
        {
            cout<<*ite2<<endl;
        }
        cout<<"****************"<<endl;
    }

    return 0;

}
