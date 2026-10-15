class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res=0;
        int prevEnd=intervals[0][1];
        int n=intervals.size();
        for(int i=1; i<n; i++){
            if(intervals[i][0]>=prevEnd){
                prevEnd=intervals[i][1];
            }
            else{
                prevEnd=min(intervals[i][1], prevEnd);
                res+=1;
            }
        }
        return res;
    }
};
