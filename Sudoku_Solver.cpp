#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board){
        if(board.size()<9 || board[0].size()<9) return;
        bool find = solSudoku(board, 0, 0);
    }

    bool solSudoku(vector<vector<char>> &board, int irow, int icol){

        int irow2, icol2;

        if(icol ==8)
        {
           irow2 = irow+1;
           icol2 = 0;
        }
        else
        {
            irow2 = irow;
            icol2 = icol+1;
        }

        if(irow==9)
        {
            return true;
        }

        if(board[irow][icol]=='.')
        {
            for(int i=1; i<=9; i++)
            {
                board[irow][icol]='0'+i;
                if(!isValid(board,irow,icol))   //先检查能不能放数i,如果不能放,把它还原为空
                {
                    board[irow][icol]='.';
                }
                else
                {
                    if(!solSudoku(board,irow2,icol2))
                    {
                        board[irow][icol]='.';
                    }
                    else
                    {
                        return true;
                    }
                }
               
            }

            if(board[irow][icol]=='.')            //如果其中任何有空的 则返回false
            {
                return false;
            }
        }
        else
        {
            return solSudoku(board, irow2, icol2);
        }
    }

    bool isValid(vector<vector<char>> &board, int irow, int icol)
    {
        char val = board[irow][icol];
        if(val-'0'<1||val-'0'>9) return false;

        for(int i=0; i<9; i++)
        {
            if(board[irow][i]==val && i!=icol) return false;
            if(board[i][icol]==val && i!=irow) return false;
        }

        int irow0 = irow/3*3;
        int icol0 = icol/3*3;
        for(int i=irow0; i<irow0+3; i++)
        {
            for(int j=icol0; j<icol0+3; j++)
            {
                if(board[i][j]==val && (i!=irow||j!=icol)) return false;
            }
        }

        return true;
    }
};

int main(){
    vector<vector<char>> board;

    board={{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.',',','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','6','7'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};
    //board={{'5','1','9','7','4','8','6','3','2'},{'7','8','3','6','5','2','4','1','9'},{'4','2','6','1','3','9','8','7','5'},{'3','5','7','9','8','6','2','4','1'},{'2','6','4','3','1','7','5','9','8'},{'1','9','8','5','2','4','3','6','7'},{'9','7','5','8','6','3','1','2','4'},{'8','3','2','4','9','1','7','5','6'},{'6','4','1','2','7','5','9','8','3'}};
    Solution s;
    s.solveSudoku(board);

    for(auto ite=board.begin();ite!=board.end();ite++)
    {
        vector<char> row=*ite;
        for(auto ite1=row.begin();ite1!=row.end();ite1++)
        {
            cout<<*ite1<<endl;
        }

        cout<<"**********************"<<endl;
    }
    return 0;
}
