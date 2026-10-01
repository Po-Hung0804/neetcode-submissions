class Solution {
public:
    int rob(vector<int>& nums) {
        // run the dfs twice
        // one from 0 to nums.size-2
        // second from 1 to nums.size-1
        if (nums.size() == 1) return nums[0];
        return max(dfs(vector<int>(nums.begin(), nums.end() - 1)), dfs(vector<int>(nums.begin() + 1, nums.end())));
    }
    int dfs(const vector<int>& nums){
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp.back();
    }
};