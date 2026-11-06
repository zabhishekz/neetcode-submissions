class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()){
            return "";
        }
        unordered_map<char,int> countT;
        for(auto a: t){
            countT[a]++;
        }
        unordered_map<char,int> window;
        int have = 0;
        int need = countT.size();
        pair<int,int> res = {-1,-1};
        int resLen = INT_MAX;

        int l = 0;
        int r = 0;
        while(r < s.length()){
            window[s[r]]++;
            if(countT.find(s[r]) != countT.end() and countT[s[r]] == window[s[r]]){
                have++;
            }
            while(have == need){
                if(r-l+1 <= resLen){
                    resLen = r-l+1;
                    res = {l,r};
                }

                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
            r++;
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
