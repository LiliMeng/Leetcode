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
            int x= middle/n;   //这里的关键在于middle/n middle是一群数的中点, 每行是n个  middle/n是中间值所处的行数, 每行放5个, middle/5 就是已经分配了几行了 因为这里是从0行开始,所以middle/5是middle所在的行数, 给了几行后, middle%5就是所在的列数
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
