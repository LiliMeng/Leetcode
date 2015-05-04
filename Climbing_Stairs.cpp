/* It was solved by a Fibonacci numbers algorithms taught in (MIT Algorithms)

First, an array is established to memorize the numbers, and then the numbers in the MemoryArray is adopted for recursion*/ 


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

/* The dynamic programming divide an overall problem to several subproblems. Often using a more naive method, many subproblems are generated and solved many times. 
The dynamic programming algorithms seek to solve every subproblem only once */
