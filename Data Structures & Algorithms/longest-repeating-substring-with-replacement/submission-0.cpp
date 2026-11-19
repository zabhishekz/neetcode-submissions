class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        
        unordered_map<char, int> mp;
        int maxFreq = 0;
        int ans = 0;

        while (j < n) {
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);

            if ((j - i + 1) - maxFreq <= k) {
                ans = max(ans, j - i + 1);
            }

            while ((j - i + 1) - maxFreq > k && i <= j) {
                mp[s[i]]--;
                i++;
            }

            j++;
        }

        return ans;
    }
};
