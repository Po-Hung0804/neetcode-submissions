class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // use xor to find the missing number 
        // a xor a = 0 
        // so we just need to pair the index and the value of nums[i] the xor value will be 0
        // the initial value of value need to be the n because the index can not to reach n  n will be the length of nums
        int n=nums.size();
        int res=n;
        for(int i=0; i<n; i++){
            res^=i^nums[i];
        }
        return res;
    }
};
