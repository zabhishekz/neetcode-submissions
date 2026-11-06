class Solution {
public:
    int rec(int n, vector<int> &dp){
        if(dp[n] != -1){
            return dp[n];
        }
        if(n == 0){
            return dp[n] = 0;
        }
        if(n == 1){
            return dp[n] = 1;
        }
        if(n == 2){
            return dp[n] = 2;
        }
        return dp[n] = rec(n-1,dp)+rec(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return rec(n,dp);
    }
};
