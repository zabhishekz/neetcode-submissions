class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(int i = 0; i < strs.size(); i++){
            int len = strs[i].size();
            result = result + to_string(len) + "#" + strs[i];
        }
        cout<<result;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while(i < s.length()){
            string temp;
            while(s[i] != '#' and i < s.length()){
                temp += s[i];
                i++;
            }
            i++;
            int len = stoi(temp);

            string tempres;
            while(len > 0 and i < s.length()){
                tempres += s[i];
                i++;
                len--;
            }
            result.push_back(tempres);
        }
        return result;
    }
};
