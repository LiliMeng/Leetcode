//如果不是happy number的话 会不停地循环 但里面就是不包含1  如果包含1就是happy number了 

class Solution {
public:
    bool isHappy(int n) {
        
        unordered_map<int, int> htable;
        
        while(n!=1)
        {
            int sum=0;
            
            while(n>0)
            {
                sum=sum+(n%10)*(n%10);  //sum=sum+(n%10)*(n%10) n/10的余数 为了保证个位数字
                n=n/10;  //n=n/10 
            }
            
            n=sum;  //每次加完后新的n值就是上次的sum
            
            if(htable.find(n)==htable.end())   //如果n不在htable里面 就把n插入到htable  如果n在htable里面就break循环 因为发现一直在循环了 在不停地循环但就是不包含1 
            {
                htable.insert({n,1});
            }
            else
            {
                return false;
            }
        }
        
       return true; 
      
        
    }
};
