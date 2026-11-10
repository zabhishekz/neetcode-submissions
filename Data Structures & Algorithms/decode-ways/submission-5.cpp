class Solution {
public:
    int dfs(int i, string &s, vector<int> &dp){
        if (i == s.size()) {
            return dp[i] = 1;
        }
        if (s[i] == '0') {
            return dp[i] = 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = dfs(i+1, s,dp);

        if (i+2 <= s.size()) {
            if (s[i] == '1' || (s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6')) {
                ans += dfs(i+2,s,dp);
            }
        }

        return dp[i] = ans;
    } 
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return dfs(0,s,dp);
    }
};
