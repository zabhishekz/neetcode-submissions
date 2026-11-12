class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms = *max_element(nums.begin(),nums.end());
        int cs = 0;
        for(auto num: nums){
            if(cs < 0){
                cs = 0;
            }
            cs += num;
            ms = max(ms,cs);
        }
        return ms;
    }
};
