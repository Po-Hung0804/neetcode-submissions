class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=1; i<n+1; i++){
            int number=i;
            while(number){
                number&=(number-1);
                res[i]++;
            }
        }
        return res;
    }
};
