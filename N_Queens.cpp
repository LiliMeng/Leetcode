#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> allSol;      // 这个用来放所有的解
        vector<string> currSol;                           //这是一个解
        vector<int> numSol;                         //   这个也是用来表示解的   用的是一个数组 用数字表示棋子放在什么位置
        solveNQ(allSol, currSol, numSol, n, 0);
        return allSol;
    }

    void solveNQ(vector<vector<string>> &allSol,vector<string> &currSol, vector<int> &numSol,int n,int irow) {
        if(irow==n) {
            allSol.push_back(currSol);             // 这个就是已经放入了 n和棋子 了 所以就把当前解放入 allsol里面
            return;
        }

        for(int icol=0; icol<n; icol++) {                        //每一层有n种摆法  这里有个for循环 冲 0到 n-1 一个n种
            if(validPos(numSol, irow, icol)) {             //这个就是一个用来判断当前摆的棋子是不是和之前摆的棋子有冲突的函数
                string s(n,'.');                                   // 不冲突就摆进去
                s[icol] = 'Q';
                currSol.push_back(s);
                numSol.push_back(icol);
                solveNQ(allSol,currSol,numSol,n,irow+1);   //这里就是回朔了，如果用树状图的思路来想就是回到了上一层。因为这个数据结构的关系 不要分支已经被自动剪掉了。
                currSol.pop_back();
                numSol.pop_back();
            }
        }
    }

    bool validPos(vector<int> &numSol, int irow, int icol) {  // 这个只是个判断函数
        if(irow<numSol.size()) return false;
        for(int i=0; i<numSol.size(); i++) {
            if(icol==numSol[i] || abs(irow-i)==abs(icol-numSol[i]))
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<string> > result=s.solveNQueens(8);
    cout<<result.size()<<endl;
    for(auto ite=result.begin();ite!=result.end();ite++)
    {
        vector<string> re=*ite;
        for(auto ite2=re.begin();ite2!=re.end();ite2++)
        {
            cout<<*ite2<<endl;
        }
        cout<<"*************"<<endl;
        }
    return 0;
    }

