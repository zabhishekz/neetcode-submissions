class Solution {
public:
int subsetSum(vector<int>& nums, int n, int sum, vector<vector<int>> &dp){
        if(sum == 0 and n == 0){
            return 1;
        }
        if(sum!= 0 and n == 0){
            return 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        if(nums[n-1] <= sum){
            return dp[n][sum] = subsetSum(nums, n-1, sum, dp) + subsetSum(nums, n-1, sum-nums[n-1], dp);
        }
        else{
            return dp[n][sum] = subsetSum(nums, n-1, sum, dp);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (abs((long long)target) > sum || (sum + target) % 2 != 0) {
            return 0;
        }

        int s1 = (sum + target) / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(s1 + 1, -1));
        
        return subsetSum(nums, nums.size(), s1, dp);
    }
};
