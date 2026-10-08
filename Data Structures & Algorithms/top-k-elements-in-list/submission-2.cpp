class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> um;
        for(auto &num: nums){
            um[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto &p: um){
            pq.push(make_pair(p.second, p.first));
            while(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
