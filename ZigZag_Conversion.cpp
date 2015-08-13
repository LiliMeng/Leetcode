class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
        {
            return s;
        }
        string res(s.size(),' ');
        int m=0;
        int interval=2*numRows-2;
        int k=0;
        for(int i=0; i<s.size();i=i+interval)
        {
            res[k]=s[i];
            k++;
        }  //处理第一行
        
        for(int i=1; i<numRows-1; i++)
        {
            int inter = (i<<1);
            for(int j = i; j < s.size(); j += inter)
            {
                res[k++] = s[j];
                inter = interval - inter;
            }
        }
        
        for(int i=numRows-1; i<s.size(); i=i+interval)
        {
            res[k]=s[i];
            k++;
        }  
        
        return res;
    }
};
