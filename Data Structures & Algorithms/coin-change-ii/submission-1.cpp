class Solution {
public:
    int unboundedKnapsack(vector<int>& coins,int amount, int n, vector<vector<int>>& dp){
        if(amount == 0){
            return 1;
        }
        if(amount != 0 and n == 0){
            return 0;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        if(coins[n-1] <= amount){
            return dp[n][amount] = unboundedKnapsack(coins, amount-coins[n-1], n,dp) + unboundedKnapsack(coins, amount, n-1,dp);
        }
        else{
            return dp[n][amount] = unboundedKnapsack(coins, amount, n-1,dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1, -1));
        return unboundedKnapsack(coins, amount, coins.size(),dp);
    }
};
