class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < position.size(); i++) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());

        stack<double> st;
        for(int i = 0; i < pairs.size(); i++){
            double time = (double)(target-pairs[i].first)/pairs[i].second;
            if(st.empty() or time > st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};
