//这个是普通的算法, leetcode通不过. 学神说kmp算法很快,对于网页上的aaabbbb这种很快. 但对于实际问题并不快

#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

     for(int i=0; i<haystack.size(); i++)
     {
         int j=0;
         int k=i;
         for( ; j<needle.size()&&k<haystack.size(); j++,k++)
         {
             if(haystack[k]!=needle[j])
             {
                 break;
             }
         }

         if(j==needle.size())
         {
             return i;
         }
     }

     return -1;
    }
};

int main()
{
    Solution s;
    cout<<s.strStr("Summer","mer")<<endl;
}
