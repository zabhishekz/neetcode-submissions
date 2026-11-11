class Solution {
public:
    int subsetSum(vector<int>& nums, int n, int sum, vector<vector<int>> &dp){
        if(sum == 0){
            return dp[n][sum] = 1;
        }
        if(sum!= 0 and n == 0){
            return dp[n][sum] = 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        if(nums[n-1] <= sum){
            return dp[n][sum] = subsetSum(nums, n-1, sum, dp) or subsetSum(nums, n-1, sum-nums[n-1], dp);
        }
        else{
            return dp[n][sum] = subsetSum(nums, n-1, sum, dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums){
            sum += num;
        }
        if(sum%2 != 0){
            return false;
        }
        int psum = sum/2;int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(psum + 1, -1));
        return subsetSum(nums, n, psum, dp);
    }
};
