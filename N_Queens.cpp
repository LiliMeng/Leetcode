#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> allSol;      // 这个用来放所有的解
        vector<string> sol;                           //这是一个解
        vector<int> col;                         //   这个也是用来表示解的   用的是一个数组 用数字表示棋子放在什么位置
        solveNQ(n, 0, col, sol, allSol);
        return allSol;
    }

    void solveNQ(int n, int irow, vector<int> &col, vector<string> &sol, vector<vector<string>> &allSol) {
        if(irow==n) {
            allSol.push_back(sol);             // 这个就是已经放入了 n和棋子 了 所以就把当前解放入 allsol里面
            return;
        }

        for(int icol=0; icol<n; icol++) {                        //每一层有n种摆法  这里有个for循环 冲 0到 n-1 一个n种
            if(validPos(col, irow, icol)) {             //这个就是一个用来判断当前摆的棋子是不是和之前摆的棋子有冲突的函数
                string s(n,'.');                                   // 不冲突就摆进去
                s[icol] = 'Q';
                sol.push_back(s);
                col.push_back(icol);
                solveNQ(n, irow+1, col, sol, allSol);   //这里就是回朔了，如果用树状图的思路来想就是回到了上一层。因为这个数据结构的关系 不要分支已经被自动剪掉了。
                sol.pop_back();
                col.pop_back();
            }
        }
    }

    bool validPos(vector<int> &col, int irow, int icol) {  // 这个只是个判断函数
        if(irow<col.size()) return false;
        for(int i=0; i<col.size(); i++) {
            if(icol==col[i] || abs(irow-i)==abs(icol-col[i]))
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
        }
    return 0;
    }
