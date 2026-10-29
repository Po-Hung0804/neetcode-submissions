class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // brute force change n to string and reverse it to get the answer 
        string number="";
        for(int i=0; i<32; i++){
            if(n&(1<<i)){
                number+='1';
            }
            else{
                number+='0';
            }
        }
        uint32_t res=0;
        for(int i=0; i<32; i++){
            if(number[31-i]=='1'){
                res|=(1<<i);
            }
        }
        return res;
    }
};
