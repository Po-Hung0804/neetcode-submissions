class Solution {
public:
    bool isPalindrome(string s) {
        // use isalnum to skip the non-alphanumeric characters element
        // use tolower to change the highercase to lowercase character
        int l=0;        
        int r=s.size();
        while(l<r){
            while(l<r && !isalnum(s[l])) l++;
            while(l<r && !isalnum(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
