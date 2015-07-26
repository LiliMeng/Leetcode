//Shall check whether the two rectangle has overlap
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1=(C-A)*(D-B);
        int area2=(G-E)*(H-F);
        
        int overlap=0;
        
        int leftX=max(A,E);
        int leftY=max(B,F);
        int rightX=min(C,G);
        int rightY=min(D,H);
        
        
        
        if(leftX<rightX&&leftY<rightY)
        {
           overlap=(rightX-leftX)*(rightY-leftY);
        }
        else
        {
            overlap=0;
        }
        
        return area1+area2-overlap;
    }
};
