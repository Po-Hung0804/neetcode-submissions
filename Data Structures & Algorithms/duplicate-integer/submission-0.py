class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dic=defaultdict(int)
        for element in nums:
            dic[element]+=1
            if dic[element]>1:
                return True
        return False
            