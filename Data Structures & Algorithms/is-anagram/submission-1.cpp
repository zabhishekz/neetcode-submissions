#include<unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int> ums;
        unordered_map<char,int> umt;

        for(auto a: s){
            if(ums.count(a)>=1){
                ums[a]++;
            }
            else{
                ums[a] = 1;
            }
        }

        for(auto a: t){
            if(umt.count(a)>=1){
                umt[a]++;
            }
            else{
                umt[a] = 1;
            }
        }

        for(auto a: ums){
            if(a.second != umt[a.first]){
                return false;
            }
        }
        return true;
    }
};
