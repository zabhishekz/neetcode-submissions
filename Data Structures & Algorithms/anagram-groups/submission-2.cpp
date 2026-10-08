class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(const auto &str : strs){
            vector<int> count(26,0);
            for(auto c: str){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1; i <26; i++){
                key += ',' + to_string(count[i]);
            }
            um[key].push_back(str);
        }

        vector<vector<string>> res;
        for(const auto &p: um){
            res.push_back(p.second);
        }
        return res;
    }
};
