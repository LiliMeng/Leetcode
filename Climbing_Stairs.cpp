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
Often when using a more naive method, many of the subproblems are generated and solved many times. The dynamic programming approach seeks to solve each subproblem only once, thus reducing the number of computations: once the solution to a given subproblem has been computed, it is stored or "memo-ized": the next time the same solution is needed, it is simply looked up. This approach is especially useful when the number of repeating subproblems grows exponentially as a function of the size of the input.
