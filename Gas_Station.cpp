#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

       int sum=0;
       int k=0;
       int total=0;
       for(int i=0;i<gas.size();i++)
       {
           sum=sum+gas[i]-cost[i];
           if(sum<0)
           {
               k=i+1;
               sum=0;
           }

           total=total+gas[i]-cost[i];
       }

       if(total<0)
       {
           return -1;
       }
       else
       {
           return k;
       }

    }
};


int main(){

    Solution s;
    vector<int> gas={1,2};
    vector<int> cost={2,1};

    cout<<s.canCompleteCircuit(gas,cost);
    return 0;

}
