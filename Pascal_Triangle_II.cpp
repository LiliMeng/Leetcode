class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> triangle=generate(rowIndex+1);
        return triangle[rowIndex];
    }
private:
    vector<vector<int>> generate(int rowIndex)
    {
        vector<vector<int>> res;
        if(rowIndex==0)
        {
            return res;
        }
        vector<int> row={1};
        res.push_back(row);
        
        for(int i=1; i<rowIndex; i++)
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
