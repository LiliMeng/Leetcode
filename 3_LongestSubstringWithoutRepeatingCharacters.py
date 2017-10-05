class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        res, start, end = 0, 0, 0
        characterDict = {}
        for c in s:
            end +=1
            characterDict[c] = characterDict.get(c,0) +1
            while characterDict[c]>1:
                characterDict[s[start]]-=1
                start+=1
            res=max(res, end-start)
        return res
        
