class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        unordered_map<char,char> hashmap={{']','['},{')','('},{'}','{'}};
        for(char c: s){
            if(hashmap.count(c)){
                if(!stk.empty() && stk.back()==hashmap[c]){
                    stk.pop_back();
                }
                else{
                    return false;
                }
            }
            else{
                stk.push_back(c);
            }
        }
        if(!stk.empty()){
            return false;
        }
        else{
            return true;
        }
    }
};
