class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int curr_sum=0;
        int res=-10001;
        for(int i=0; i<n; i++){
            if(nums[i]>curr_sum+nums[i]){
                curr_sum=nums[i];
            }
            else{
                curr_sum+=nums[i];
            }
            res=max(res,curr_sum);
        }
        return res;
    }
};
