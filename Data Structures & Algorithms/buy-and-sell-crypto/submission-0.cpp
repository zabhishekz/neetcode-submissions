class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<int> mins;
        int currmin = prices[0];
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < currmin){
                currmin = prices[i];
            }
            ans = max(ans,prices[i]-currmin);
        }
        return ans;
    }
};
