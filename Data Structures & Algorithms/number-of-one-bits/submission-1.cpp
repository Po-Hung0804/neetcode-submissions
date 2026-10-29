class Solution {
public:
    int hammingWeight(uint32_t n) {
        // use loop to solve the time complexity is O(1) 
        /*
        int res=0;
        while(n){
            res+=(n&1)? 1:0;
            n>>=1;
        }
        return res;
        */
        // optimal solution 
        int res=0;
        while(n){
            n&=(n-1);
            res++;
        }
        return res;

    }
};
