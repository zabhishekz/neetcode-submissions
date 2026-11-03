class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;

        unordered_map<char,int> um;

        while(j < s.length()){
            if(um.count(s[j]) != 0){
                um.erase(s[i]);
                i++;
            }
            else{
                um[s[j]]++;
                j++;
                ans = max(ans, j-i);
            }
        }

        return ans;
    }
};
