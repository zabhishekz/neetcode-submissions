
#include<queue>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> um;
        vector<int> res;
        priority_queue<pair<int,int>> maxHeap; 

        for(auto a: nums){
            um[a]++;
        }

        for(auto b: um){
            maxHeap.push(make_pair(b.second, b.first));
        }

        for(auto b: um){
            cout<<b.second<<","<<b.first<<endl;
        }

        while(!maxHeap.empty() and k != 0){
            int x = maxHeap.top().second;
            maxHeap.pop();
            res.push_back(x);
            k--;
        }
        return res;
    }
};
