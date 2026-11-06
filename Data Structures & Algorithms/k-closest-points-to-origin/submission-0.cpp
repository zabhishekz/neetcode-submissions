class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxHeap;
        for(auto a: points){
            int dist = pow(a[0],2) + pow(a[1],2);
            maxHeap.push({dist,a});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
