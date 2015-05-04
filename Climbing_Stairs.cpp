#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    int MemoryArray[n];
    MemoryArray[0]=0;
    MemoryArray[1]=1;
    MemoryArray[2]=2;
    for(int i=3; i<=n; i++)
    {
        MemoryArray[i]=MemoryArray[i-1]+MemoryArray[i-2];
    }
    return MemoryArray[n];
    }
};

int main()
{
    Solution s;
    cout<<s.climbStairs(3)<<endl;
}
