class Solution {
public:
    int helper(string s, vector<string>& wordDict, int i, vector<int> &dp){
        if(i == s.size()){
            return dp[i] = 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        for(string& word: wordDict){
            int len = word.length();
            if(i+len <= s.length() and s.substr(i,len) == word){
                if(helper(s,wordDict,i+len,dp) == 1){
                    return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0;
    } 
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1, -1);
        return helper(s, wordDict, 0, dp);
    }
};
