class Solution {
public:
    vector<int> nextGreaterRight(vector<int>& nums){
        stack<pair<int,int>> st;
        vector<int> right;
        for(int i = nums.size()-1; i >= 0; i--){
            while(!st.empty() and st.top().first <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                right.push_back(st.top().second);
            }
            else{
                right.push_back(-1);
            }
            st.push(make_pair(nums[i],i));
        }
        reverse(right.begin(),right.end());
        return right;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        vector<int> indices = nextGreaterRight(temperatures);
        for(int i = 0; i <temperatures.size();i++){
            indices[i]-i > 0 ? result.push_back(indices[i]-i) : result.push_back(0);
        }
        return result;
    }
};

// [5,5,5,5,5,-1,-1]
