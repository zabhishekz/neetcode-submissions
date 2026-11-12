class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int> (prices.size()+1, -1));
        return dfs(0, true, prices, dp);
    }
    int dfs(int i, bool canBuy, vector<int> & prices, vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0;
        }
        if(dp[canBuy][i] != -1){
            return dp[canBuy][i];
        }
        if (canBuy){
            return dp[canBuy][i] = max(dfs(i+1, !canBuy, prices, dp)-prices[i], dfs(i+1, canBuy, prices,dp));
        }
        else{
            return dp[canBuy][i] =max(dfs(i+2, !canBuy, prices, dp)+prices[i], dfs(i+1, canBuy, prices, dp));
        }
    }
};
