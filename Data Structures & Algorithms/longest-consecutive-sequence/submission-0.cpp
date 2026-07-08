class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); i++){
            us.insert(nums[i]);
        }
        int longest = 0;

        for(int num: us){
            if(us.find(num-1) == us.end()){
                int len = 1;
                while(us.find(num+len) != us.end()){
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};
