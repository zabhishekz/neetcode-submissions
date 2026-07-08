class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int maxans = INT_MIN;
        while(i < j){
            int water = min(heights[i],heights[j])*(j-i);
            maxans = max(water, maxans);
            if(heights[i] <= heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxans;
    }
};
