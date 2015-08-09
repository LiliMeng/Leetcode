class Solution {
public:
    string addBinary(string a, string b) {
        
        int la = a.size() - 1;
        int lb = b.size() - 1;
        string result = la>=lb?a:b;
        int carrier = 0;
        for (int i = result.size() - 1; i >= 0; i--){  //之所以i从大到小是因为  "1111" 最低位是a.size()-1;
            int c = carrier;  //每次c的初始值是进位得到的carrier的数值
            if (la >= 0) c =c+ a[la--] - '0';  //从最高位开始往低位走, 每次的c都是最高位  最高位只可能是加起来0,1,2这三个数字
            if (lb >= 0) c =c+ b[lb--] - '0';   
            result[i] = c%2  + '0';  // 最低位的数值是c/2的余数.如果能被2整除 则为0 进一位 如果不能被2整除则为1 因为c只可能有0,1,2这三个数字
            carrier = c/2;
        }
        if (carrier==1)
            result="1"+result;
        return result;
    }
};
