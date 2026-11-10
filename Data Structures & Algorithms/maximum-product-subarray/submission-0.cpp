class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];

        int cmax = 1;
        int cmin = 1;
        for(int num: nums){
            if(num == 0){
                cmax = cmin = 1;
            }
            int tmp = cmax*num;
            cmax = max(num*cmax, max(num*cmin, num));
            cmin = min(tmp, min(num*cmin, num));
            ans = max(ans, max(cmax, cmin));
        }
        return ans;
    }
};
