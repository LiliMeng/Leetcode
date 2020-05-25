class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        if endWord not in wordList:
          return 0
        graph = self.find_neighbors(wordList, beginWord)
        
        visited_dict = {}
        node_dist = {}

        for key in graph.keys():
          visited_dict[key] = False
          node_dist[key] = 0

        neighbor_queue = [beginWord]
     
        
        count = 0
        while neighbor_queue:
          u = neighbor_queue.pop(0)
          count+=1
          print("neighbor_queue at i: ",  count, neighbor_queue)
          print("u: ", u)
          print("graph[u]: ", graph[u])
          
          for v in graph[u]:
            if visited_dict[v]==False:
              if v not in neighbor_queue:
                node_dist[v] = node_dist[u] + 1
                neighbor_queue.append(v)

          visited_dict[u]=True
          print("visited_dict: ", visited_dict)
  

        print("node_dist: ", node_dist)
        res = 0
        if node_dist[endWord]!=0:  
            res= node_dist[endWord]+1
        else:
            res= 0
        print("res: ", res)
        return res 
       

    def find_neighbors(self, wordList, beginWord):
        if beginWord not in wordList:
          wordList.append(beginWord)
        num_word = len(wordList)
        all_neighbors_dict = {}
        for i in range(num_word):
          all_neighbors_dict[wordList[i]] = []
          for j in range(num_word):
            if self.get_num_diff(wordList[i], wordList[j]) ==1:
              all_neighbors_dict[wordList[i]].append(wordList[j])
        return all_neighbors_dict

    def get_num_diff(self, s1, s2):
      common_char = []
      for i in range(len(s1)):
          if s1[i]==s2[i]:
            common_char.append(s1[i])
      num_diff = len(s1)-len(common_char)
      return num_diff

#beginWord ="a"
#endWord = "c"
#wordList = ["a","b","c"]
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
res = Solution()
res.ladderLength(beginWord, endWord, wordList)
