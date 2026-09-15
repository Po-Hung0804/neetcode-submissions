class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // we can use sort and hash map to solve it with time complexity O(m*nlong)
        // but we can just use hash map and character a-z array to solve it with O(mn)
        unordered_map<string,vector<string>> dic;
        for (const auto &s: strs){
            vector<int> count(26,0);
            for (char c : s){
                count[c-'a']++;
            }
            string key= to_string(count[0]);
            for (int i=1; i<26; i++){
                key+=','+to_string(count[i]);
            }
            dic[key].push_back(s);            
        }
        vector<vector<string>> res;
        for (const auto &pairs : dic){
            res.push_back(pairs.second);
        }
        return res;
    }
};
