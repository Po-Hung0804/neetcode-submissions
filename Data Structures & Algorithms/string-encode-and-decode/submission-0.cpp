class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string encoding_s;
        for(int i=0;i<n;i++){
            encoding_s+=to_string(strs[i].size());
            encoding_s+='#';
            encoding_s+=strs[i];
        }
        return encoding_s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        int n=s.size();
        while(i<n){
            // need another pointer to remember where is the start char is the lenght of string
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length=stoi(s.substr(i,j-i));
            res.push_back(s.substr(j+1,length));
            i=j+length+1;
        }
        return res;
    }
};
