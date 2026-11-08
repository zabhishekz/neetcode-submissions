class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k || k <= 0) return {};

        int i = 0;
        int j = 0; 
        vector<int> res;
        deque<int> q;

        while (j < n) {
            while(!q.empty() and q.back() < nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                res.push_back(q.front());
                if(nums[i] == q.front()){
                    q.pop_front();
                }
                i++;
                j++;
            }
            
        }
        return res;
    }
};
