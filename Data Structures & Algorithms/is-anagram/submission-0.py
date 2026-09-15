class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        dic=defaultdict(int)
        for element in s:
            dic[element]+=1
        for i in t:
            dic[i]-=1
            if dic[i] < 0:
                return False
        return True