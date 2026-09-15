class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // we can use hashmap and sort alg to solve it with O(nlogn)
        // but we also can use heap(priority queue) to solve it with O(n) in time complexity
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
    }
};
