class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic=defaultdict(int)
        n=len(nums)
        for i in range(n):
            new_tar=target-nums[i]
            if nums[i] in dic:
                return [dic[nums[i]],i]
            else:
                dic[new_tar]=i
        return []