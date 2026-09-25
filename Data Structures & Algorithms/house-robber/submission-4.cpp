class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return *max_element(nums.begin(),nums.end());
        for(int i=2; i<n; i++){
            if(i==2) nums[i]=nums[i]+nums[i-2];
            else nums[i]=nums[i]+max(nums[i-2],nums[i-3]);
        }
        return max(nums[n-1],nums[n-2]);
    }
};
