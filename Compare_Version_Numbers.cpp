#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        int index1 = 0;
        int index2 = 0;

        while(index1 < version1.size() || index2 < version2.size())
        {
            int curSum1 = 0;
            int curSum2 = 0;
            while(index1 < version1.size() && version1[index1] != '.')
            {
                curSum1 = curSum1*10 + version1[index1++]-'0';
                index1++;
            }
         while(index2 < version2.size() && version2[index2] != '.')
         {
             curSum2 = curSum2*10 + version2[index2++]-'0';
             index2++;
         }
        if(curSum1 > curSum2) return 1;
        if(curSum1 < curSum2) return -1;
    }
    return 0;
    }
};


int main()
{
    Solution s;
    cout<<s.compareVersion("1.1","1.2")<<endl;
}
