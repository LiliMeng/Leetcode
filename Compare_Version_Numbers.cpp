#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i=0;
        int j=0;
        
        while(i<version1.size()||j<version2.size())
        {
            int sum1 = 0;
            int sum2 = 0;
            
            while(i<version1.size()&&version1[i]!='.')
            {
                sum1=sum1*10+version1[i++]-'0';
            }
            
            while(j<version2.size()&&version2[j]!='.')
            {
                sum2=sum2*10+version2[j++]-'0';
            }
            
            i++;
            j++;
        
        
        if(sum1 > sum2) return 1;
        if(sum1 < sum2) return -1;
        //这时如果sum1!=sum2就重新开始进行下一个循环 比较下一步 比如 1.123, 1.234. 最初1都相同, 进行下一轮比较123, 234
        }
    return 0;
    }
};

int main()
{
    Solution s;
    cout<<s.compareVersion("1.1","1.2")<<endl;
}
