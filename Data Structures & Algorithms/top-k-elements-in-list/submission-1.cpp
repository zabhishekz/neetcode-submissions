#include<queue>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> um;
        vector<int> res;
        priority_queue<pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>>> minHeap; 

        for(auto a: nums){
            um[a]++;
        }

        for(auto b: um){
            minHeap.push(make_pair(b.second, b.first));
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        while(!minHeap.empty()){
            int x = minHeap.top().second;
            minHeap.pop();
            res.push_back(x);
        }
        return res;
    }
};
