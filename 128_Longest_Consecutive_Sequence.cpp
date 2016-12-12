class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
      unordered_map<int, bool> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = true;
        }
        
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            int up = nums[i];
            while (hash.find(up) != hash.end()) {
                hash.erase(up);
                up++;
            }
            int down = nums[i] - 1;
            while (hash.find(down) != hash.end()) {
                hash.erase(down);
                down--;
            }
            if (up - down - 1 > max) {
                max = up - down - 1;
            }
        }
        return max;
    }
    
};
