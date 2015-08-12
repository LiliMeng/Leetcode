class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        if(numRows==0)
        {
            return res;
        }
        vector<int> row={1};
        res.push_back(row);
        
        for(int i=1; i<numRows; i++)
        {
            row.clear();
            res.push_back(row);
            for(int j=0; j<=i; j++)
            {
                if(j==0||j==i)
                {
                    res[i].push_back(1);
                }
                else
                {
                    res[i].push_back(res[i-1][j-1]+res[i-1][j]);
                }
            }
        }
        
        return res;
    }
};
