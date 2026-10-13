class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // use binary search
        int n=intervals.size();
        if(n==0){
            return {newInterval};
        }
        int target=newInterval[0];
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(intervals[mid][0]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        intervals.insert(intervals.begin()+left,newInterval);
        vector<vector<int>> res;
        for(int i=0; i<n+1; i++){
            if(res.empty() || res.back()[1]<intervals[i][0]){
                res.push_back(intervals[i]);
            }
            else{
                res.back()[1]=max(res.back()[1], intervals[i][1]);
            }
        }
        return res;

    }
};
