class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int n=prices.size();
        int max_profit=0;
        for(int r=0; r<n; r++){
            if(prices[r]<prices[l]){
                l=r;
            }
            else{
                max_profit=max((prices[r]-prices[l]),max_profit);
            }
        }
        return max_profit;
    }
};
