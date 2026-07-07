#include<algorithm>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> us (nums.begin(),nums.end());
        if(us.size() != nums.size()){
            return true;
        }
        else {
            return false;
        }
    }
};