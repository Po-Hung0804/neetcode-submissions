class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> s=nums;
        sort(s.begin(),s.end());
        int n=nums.size();
        int max_diff=s[n-1]+s[n-2];
        vector<vector<int>> res;
        for(int i=0; i<n-2; i++){
            if(i > 0 && s[i] == s[i-1]) continue;
            int temp=s[i]*(-1);
            if(temp<0 or temp>max_diff) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(s[j]+s[k]==temp){
                    res.push_back({s[i],s[j],s[k]});
                    while(j<k && s[j]==s[j+1]) j++;
                    while(j<k && s[k]==s[k-1]) k--;
                    j++;
                    k--;
                }
                else if(temp>s[j]+s[k]){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return res;
    }
};
