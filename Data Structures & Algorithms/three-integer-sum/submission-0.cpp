class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> us;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-1; i++){
            int j = i+1;
            int k = nums.size()-1;

            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    vector<int> temp {nums[i], nums[j] ,nums[k]};
                    for(auto a: temp){
                        cout<<a<<",";
                    }
                    j++;
                    k--;
                    us.insert(temp);
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        for(auto a: us){
            result.push_back(a);
        }
        return result;
    }
};
