class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        dic=defaultdict(int)
        for element in s:
            dic[element]+=1
        for i in t:
            if i not in dic:
                return False
            dic[i]-=1
            if dic[i] < 0:
                return False
        return True