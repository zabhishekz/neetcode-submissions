class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        unordered_map <int, int> um;
        for(int i = 0; i < nums.size(); i++){
            um[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int tofind = target - nums[i];
            if(um.find(tofind) != um.end()){
                if(um[tofind] != i){
                    return {i, um[tofind]};
                }
            }
        }

        return {};
    }
};
