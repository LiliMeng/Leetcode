#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {

      vector<int> count(256, 0);

      for (auto a : s) ++count[a];
      bool flag = false;
      for (auto n : count)
      {
        if (n & 1)
        {
            if (!flag)
            {
               flag = true;
            }
            else
            {
                return false;
            }
        }
        return true;
      }
    }
};

int main()
{
    Solution sol;
    string s="aab";
    cout<<sol.canPermutePalindrome(s)<<endl;
    return 0;
}
