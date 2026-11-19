class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int ans = 0; // 0 handles empty string "" properly

        while (j < n) {
            mp[s[j]]++;
            
            // All characters in window [i, j] are unique
            if (mp.size() == j - i + 1) {
                ans = max(ans, j - i + 1);
            }

            // Shrink window while there are duplicate characters
            while (mp.size() < j - i + 1) {
                mp[s[i]]--; 
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};
