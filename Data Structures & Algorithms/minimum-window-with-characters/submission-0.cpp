class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()==0){
            return "";
        }
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for(auto &c:t){
            t_map[c]++;
        }
        int resLen=INT_MAX, l=0, need=t_map.size(), have=0;
        pair<int,int> res={-1,-1};
        int n=s.size();
        for(int r=0; r<n; r++){
            char element=s[r];
            s_map[element]++;
            if(t_map.count(element) && s_map[element]==t_map[element]){
                have++;
            }
            // we shrink the window size if have==need
            while(have==need){
                if(r-l+1<resLen){
                    resLen=r-l+1;
                    res={l,r};
                }
                s_map[s[l]]--;
                if(t_map.count(s[l]) && s_map[s[l]]<t_map[s[l]]){
                    have--;
                }
                l++;
            }
        }
        if(resLen!=INT_MAX){
            return s.substr(res.first,resLen);
        }
        else{
            return "";
        }
    }
};
