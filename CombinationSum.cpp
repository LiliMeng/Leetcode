#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {


    vector<vector<int>> allComb;
    if(candidates.size() == 0 || target < 0)
    return allComb; //condition qualification check

    vector<int> currComb;
    sort(candidates.begin(),candidates.end());
    backtracking(allComb,currComb,candidates,target,0);
    return allComb;
    }

    void backtracking(vector<vector<int>>& allComb, vector<int>& currComb, vector<int>& candidates, int target, int level)
    {
        if(target==0)
        {
            allComb.push_back(currComb);
            return;
        }
        else if(target<0)
        {
            return;
        }

        for(int i=level;i<=candidates.size() ;i++)
        {
            target=target-candidates[i];
            currComb.push_back(candidates[i]);
            backtracking(allComb,currComb,candidates,target,i+1);
            currComb.pop_back();
            target=target+candidates[i];
        }
    }


};


int main(){
    Solution s;
    vector<vector<int>> allComb;
    vector<int> currComb;
    vector<int> candidates={1,2,3};
    allComb=s.combinationSum(candidates,3);
    for(auto ite=allComb.begin();ite!=allComb.end();ite++)
    {
        vector<int> currComb=*ite;

        for(auto ite2=currComb.begin();ite2!=currComb.end();ite2++)
        {
            cout<<*ite2<<endl;
        }
        cout<<"****************"<<endl;
    }

    return 0;

}
