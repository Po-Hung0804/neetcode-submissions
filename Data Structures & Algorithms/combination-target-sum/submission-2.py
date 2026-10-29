class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        # need to build the real path and backtracking 
        # use dfs with some cut off way  
        path=[]
        ans=[]
        n=len(nums)
        nums.sort()
        if n==1 and nums[0]>target:
            return []
        def dfs(i, t):
            if t==0:
                ans.append(path.copy())
                return 
            for j in range(i,n):
                if t-nums[j]<0:
                    break
                path.append(nums[j])
                dfs(j, t-nums[j])
                path.pop()
        dfs(0, target)
        return ans