class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mT;
        for(auto a: t){
            mT[a]++;
        }
        int countT = mT.size();
        
        int n = s.size();
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (j < n) {
            if(mT.count(s[j])){
                mT[s[j]]--;
                if(mT[s[j]]==0){
                    countT--;
                }
            }

            while(countT == 0){
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startIdx = i;
                }

                if(mT.count(s[i])){
                    mT[s[i]]++;
                    if (mT[s[i]] > 0) {
                        countT++;
                    }
                }
                i++;
            }
            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
