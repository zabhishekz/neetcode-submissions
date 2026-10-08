class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto a : nums){
            if(freq[a]){
                freq[a]++;
                return true;
            }
            else{
                freq[a]=1;
            }
        }
        return false;
    }
};