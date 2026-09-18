class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        int pivot=l;
        int result=binary_search(nums,0,pivot-1,target);
        if(result!=-1){
            return result;
        }
        return binary_search(nums,pivot,nums.size()-1,target);
    }
    int binary_search(vector<int> &nums, int left, int right, int target){
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return -1;
    }
};
