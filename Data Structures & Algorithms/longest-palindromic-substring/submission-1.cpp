class Solution {
public:
    string longestPalindrome(string s) {
        int resIdx = 0;
        int resLen = 0;

        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i;
            while(l>= 0 and r < s.size() and s[l] == s[r]){
                if(r-l+1 > resLen){
                    resIdx = l;
                    resLen = r-l+1;
                }
                l--;
                r++;
            }
        }

        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i+1;
            while(l>= 0 and r < s.size() and s[l] == s[r]){
                if(r-l+1 > resLen){
                    resIdx = l;
                    resLen = r-l+1;
                }
                l--;
                r++;
            }
        }

        return s.substr(resIdx, resLen);
    }
};
