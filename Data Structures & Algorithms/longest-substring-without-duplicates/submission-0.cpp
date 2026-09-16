class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hashmap;
        int l=0;
        int res=0;
        int n=s.size();
        for(int r=0; r<n; r++){
            hashmap[s[r]]++;
            while(hashmap[s[r]]>1){
                hashmap[s[l]]--;
                l++;
            }           
            res=max(res,r-l+1); 
        }
        return res;
    }
};
