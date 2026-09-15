class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // use hash set to solve it with time complextiy O(n)
        int n=nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        if(n==0) return 0;
        int res=1;
        for(int &num : nums){
            if(s.count(num-1)) continue;
            int temp=num+1;
            int ans=1;
            while(s.count(temp)){
                ans++;
                temp++;
            }
            res=max(ans,res);
        }
        return res;
    }
};
