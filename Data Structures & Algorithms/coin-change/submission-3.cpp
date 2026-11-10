class Solution {
public:
    int unboundedKnapsack(vector<int>& coins, int n, int amount,vector<vector<int>>&dp) {
        if(amount == 0){
            return dp[n][amount] = 0;
        }
        if(amount < 0 or n == 0){
            return dp[n][amount] = 1e9;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        if(coins[n-1] <= amount){
            return dp[n][amount] = min(unboundedKnapsack(coins, n-1, amount,dp), 1 + unboundedKnapsack(coins, n, amount-coins[n-1],dp));
        }
        else{
            return dp[n][amount] = unboundedKnapsack(coins, n-1, amount,dp);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1, -1));
        int ans = unboundedKnapsack(coins, coins.size(), amount, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
