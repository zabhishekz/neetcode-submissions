class Solution {
public:
    vector<int> nsl(vector<int>& nums){
        vector<int> left;
        stack<int> st;
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() and nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                left.push_back(st.top());
            }
            else{
                left.push_back(-1);
            }
            st.push(i);
        }
        return left;
    }
    vector<int> nsr(vector<int>& nums){
        vector<int> right;
        stack<int> st;
        for(int i = nums.size()-1; i >=0; i--){
            while(!st.empty() and nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                right.push_back(st.top());
            }
            else{
                right.push_back(nums.size());
            }
            st.push(i);
        }
        reverse(right.begin(),right.end());
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = nsl(heights);
        vector<int> right = nsr(heights);
        for(auto a: left){
            cout<<a<<"," ;
        }
        cout<<endl;
        for(auto a: right){
            cout<<a<<", ";
        }
        int maxans = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            int tempans = heights[i]*(right[i]-left[i]-1);
            maxans = max(maxans, tempans);
        }
        return maxans;
    }
};
