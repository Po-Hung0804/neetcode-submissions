class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // use two array one is prefix the other is suffix
        int n=nums.size();
        vector<int> prefix(n+1);
        vector<int> suffix(n+1);
        prefix[0]=1;
        suffix[n]=1;
        for(int i=0; i<n; i++){
            prefix[i+1]=prefix[i]*nums[i];
        }
        for(int j=n-1; j>=0; j--){
            suffix[j]=suffix[j+1]*nums[j];
        }
        vector<int> res(n);
        for(int k=0; k<n; k++){
            res[k]=prefix[k]*suffix[k+1];
        }
        return res;
    }
};
