class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSets;
        vector<int> sol;
        allSets.push_back(sol);
        sort(nums.begin(),nums.end());
        findSubsets(nums, 0, sol, allSets);
        return allSets;
    }
    
    void findSubsets(vector<int> &nums, int start, vector<int> &sol, vector<vector<int>> &allSets) {
        for(int i=start; i<nums.size(); i++) {
            sol.push_back(nums[i]);
            allSets.push_back(sol);
            findSubsets(nums, i+1, sol, allSets);
            sol.pop_back();
        }
    }
};
