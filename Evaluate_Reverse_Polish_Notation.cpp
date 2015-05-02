#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

    stack<int> operand;

    for(int i=0; i<tokens.size(); i++)
    {
        if((tokens[i][0]=='-'&& tokens[i].size()>1)|| (tokens[i][0]>='0'&& tokens[i][0]<='9'))
        {
            operand.push(atoi(tokens[i].c_str()));
            continue;
        }

        int operand1=operand.top();
        operand.pop();
        int operand2=operand.top();
        operand.pop();
        if(tokens[i]=="+")  operand.push(operand2+operand1);
        if(tokens[i]=="-")  operand.push(operand2-operand1);
        if(tokens[i]=="*")   operand.push(operand2*operand1);
        if(tokens[i]=="/")   operand.push(operand2/operand1);
    }
        return operand.top();

    }
};

int main(){

    Solution s;
    vector<string> t{"2","3","5","*","+"};
    cout<<s.evalRPN(t)<<endl;
    return 0;


}
