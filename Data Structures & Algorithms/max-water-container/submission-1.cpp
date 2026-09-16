class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA=0;
        int l=0;
        int r=heights.size()-1;
        while(l<r){
            int h=min(heights[l],heights[r]);
            maxA=max(h*(r-l),maxA);
            while(l<r && heights[l]<=h) l++;
            while(l<r && heights[r]<=h) r--;
        }
        return maxA;
    }
};
