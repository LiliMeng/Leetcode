class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0'||grid[i][j]=='2') 
                {
                    continue;
                }
                ans++;
                dfs(grid, i, j);
            }
        }
        return ans;
    }


    void dfs(vector<vector<char>> &grid, int i, int j) {

        int m = grid.size();
        int n = grid[0].size();


        if (i < 0 || i >= m || j < 0 || j >= n) return;

        if (grid[i][j] == '1') {
            grid[i][j] = '2';
            dfs(grid, i - 1, j);
            dfs(grid, i + 1, j);
            dfs(grid, i, j - 1);
            dfs(grid, i, j + 1);
        }
    }
};

/*
所有的横竖连成一片的算一个岛，Example1的一片１全都连在一起了算是一个岛

11110
11010
11000
00000

Example2的前两行的４个１连成一个岛，第三行的一个１算一个岛，　最后一行的两个１算一个岛
11000
11000
00100
00011

*/
