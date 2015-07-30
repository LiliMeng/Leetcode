class Solution {
public:
    vector<int> grayCode(int n) {
    
      vector<int> result;      
      result.push_back(0);  
      for(int i=0; i< n; i++)  
      {  
        int highestBit = 1<<i;  
        for(int i = result.size()-1; i>=0; i--)  
        {  
          result.push_back(highestBit + result[i]);  
        }  
      }  
      return result;
    }
};

/*第一次 result这个vector里只有0
当i=0时, 1向左移动0位
result.size()-1=0  这时把(1+0)push进去 就是1

第二次 i=1 result这个vector里有0,1 
highestBit为 10 即1向左移动1位
result.size()-1=1 这时要push (1+10)和(0+10)进去 result里面有 0,1,11,10

第三次 i=2 result里有[0,1,11,10]
highestBit为 100 即1向左移动2位
result.size()-1=3, 这时要push(10+100),(11+100),(1+100),(0+100)进去 result为[0,1,11,10,110,111,101,100]

第四次
highestBit为 1000
result为[000,001,011,010,0110,0111,0101,0100,1000,1101,1111,1010,1011,1001,1000]



