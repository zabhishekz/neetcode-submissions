class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;

        vector<int> prevWindow = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(prevWindow[1] < intervals[i][0]){
                res.push_back(prevWindow);
                prevWindow = intervals[i];
            }
            else{
                prevWindow[1] = max(prevWindow[1],intervals[i][1]);
            }
        }

        res.push_back(prevWindow);
        return res;
    }
};
