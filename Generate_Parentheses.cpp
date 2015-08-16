class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        if(n==0) return res;
        gp("",0,0,n,res);
        return res;
}
    void gp(string s, int l, int r, int &n, vector<string> &res)
    {
        if(l>n) return;
    
        if(l<n)
        {
            gp(s+"(",l+1,r,n,res);
        }
        
        if(r<l)
        {
            gp(s+")",l,r+1,n,res);
        }
        
        if(s.size()==2*n)
        {
            res.push_back(s);
        }
    }

};
