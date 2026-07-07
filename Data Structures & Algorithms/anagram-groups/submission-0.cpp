class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        unordered_map <string, vector<string>> um;
        
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            um[strs[i]].push_back(temp);
        }

        for(auto i : um){
            result.push_back(i.second);
        }
        return result;
    }
};
