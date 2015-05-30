#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

    vector<vector<int>> allComb;
    vector<int> currComb;
    backtracking(allComb,currComb,n,k,1);
    return allComb;
    }

    void backtracking(vector<vector<int> > &allComb, vector<int> &currComb, int n, int k, int level)
    {
        if(currComb.size()==k)
        {
            allComb.push_back(currComb);
            return;
        }
        for(int i=level;i<=n;i++)
        {
            currComb.push_back(i);
            backtracking(allComb,currComb,n,k,i+1);
            currComb.pop_back();
        }
        }

};


int main(){
    Solution s;
    vector<vector<int>> allComb;
    vector<int> currComb;

    allComb=s.combine(4,2);
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
