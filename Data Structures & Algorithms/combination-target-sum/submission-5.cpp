class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    void dfs(int i, int target, const vector<int>& nums) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] > target) break;      
            cur.push_back(nums[j]);
            dfs(j, target - nums[j], nums);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // find the real path or like backtracking problem we will need to use dfs 
        sort(nums.begin(), nums.end());
        dfs(0,target, nums);
        return res;
    }

};
