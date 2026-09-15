class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // use two array one is prefix the other is suffix
        /*
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
        */
        // we can reduce one for loop with take suffix as one int res and return preffix
        int n=nums.size();
        vector<int> prefix(n);
        int res=1;
        prefix[0]=1;
        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int j=n-1; j>=0; j--){
            prefix[j]=res*prefix[j];
            res*=nums[j];
        }
        return prefix;
    }
};
