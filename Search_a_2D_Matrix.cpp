class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        if(m==0)
        {
            return false;
        }
        int n=matrix[0].size();
        if(n==0)
        {
            return false;
        }
        
        int start = 0;
        int end = m*n -1;
        
        while(start<=end)
        {
            int middle=(start+end)/2;
            int x= middle/n;
            int y= middle%n;
            if(matrix[x][y]==target)
            {
                return true;
            }
            else if(matrix[x][y]<target)
            {
                start=middle+1;
            }
            else
            {
                end=middle-1;
            }
        }
        return false;
    }
};
