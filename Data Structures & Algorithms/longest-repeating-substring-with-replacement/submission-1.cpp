class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int n=s.size();
        // use hashtable to track the frequency of current window
        // use brute force with fixed l with time complexity O(n^2) this will TLE
        // so we have to use sliding window
        /*
        for(int l=0; l<n; l++){
            int max_f=0;
            vector<int> cnt(26,0);
            for(int r=l; r<n; r++){
                cnt[s[r]-'A']++;
                max_f=max(max_f,cnt[s[r]-'A']);
                if(r-l+1-max_f<=k){
                    ans=max(ans,r-l+1);
                }
            }
        }
        return ans;
        */
        // r-l+1-max frequency is the number that we have to replace
        int l=0;
        int max_f=0;
        vector<int> cnt(26,0);
        for(int r=0 ;r<n; r++){
            cnt[s[r]-'A']++;
            max_f=max(max_f,cnt[s[r]-'A']);
            while(r-l+1-max_f>k){
                // the max_f can change or not since when the max_f is the largest one the ans is the longest
                cnt[s[l]-'A']--;
                // max_element will return the pointer point to the value in the cnt array so we have use * to get the value
                max_f= *max_element(cnt.begin(),cnt.end());
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
