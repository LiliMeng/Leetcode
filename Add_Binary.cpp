class Solution {
public:
    string addBinary(string a, string b) {
        
        int la = a.size() - 1;
        int lb = b.size() - 1;
        string result = la>=lb?a:b;
        int carrier = 0;
        for (int i = result.size() - 1; i >= 0; i--){
            int c = carrier;
            if (la >= 0) c =c+ a[la--] - '0';
            if (lb >= 0) c =c+ b[lb--] - '0';
            result[i] = c%2  + '0';
            carrier = c/2;
        }
        if (carrier==1)
            result="1"+result;
        return result;
    }
};
