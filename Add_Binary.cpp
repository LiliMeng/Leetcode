class Solution {
public:
    string addBinary(string a, string b) {
        
        int la = a.size() - 1;
        int lb = b.size() - 1;
        string result = la>=lb?a:b;
        int carryon = 0;
        for (int i = result.size() - 1; i >= 0; i--){
            int c = carryon;
            if (la >= 0) c =c+ a[la--] - '0';
            if (lb >= 0) c =c+ b[lb--] - '0';
            result[i] = c%2  + '0';
            carryon = c/2;
        }
        if (carryon==1)
            result="1"+result;
        return result;
    }
};
