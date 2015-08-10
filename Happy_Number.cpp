class Solution {
public:
    bool isHappy(int n) {
        
        unordered_map<int, int> m;
        while (n != 1) {
            int sum = 0;
            while (n > 0) {
                sum += ((n % 10) * (n % 10));
                n /= 10;
            }
            n = sum;
            if (m.find(n) != m.end()) break;
            else m[n] = 1;
        }
        return n == 1;
        
    }
};
