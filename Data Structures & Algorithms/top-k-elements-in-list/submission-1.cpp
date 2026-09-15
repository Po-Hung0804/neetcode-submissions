class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // we can use hashmap and sort alg to solve it with O(nlogn)
        // but we also can use heap(priority queue) to solve it with O(m log k), where m is the number of distinct elements. Each element goes through one push and at most one pop, and the heap size stays bounded at k, so each operation costs O(log k).
        // so the best solution is bucket sort with O(n) 
        /*
        vector<int> res;
        priority_queue<pair<int,int>> qp;
        unordered_map<int,int> hashmap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            hashmap[nums[i]]++;
        }
        for(auto &[key,val]:hashmap){
            qp.push({val,key});
        }
        for(int j=0;j<k;j++){
            auto [a,b]=qp.top(); qp.pop();
            res.push_back(b);
        }
        return res;
        */
        // the bucket solution tips is mapping the value of counter to the 2D array and enumeration it in decreasing pattern
        int n=nums.size();
        unordered_map<int,int> cnt;
        vector<vector<int>> bucket(n+1);
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        for(auto &[key,val]:cnt){
            bucket[val].push_back(key);
        }
        vector<int> res;
        for(int j=n;j>=0;j--){
            for(auto &num:bucket[j]){
                res.push_back(num);
                if(res.size()==k){
                    return res;
                }
            }
        }
    }
};
