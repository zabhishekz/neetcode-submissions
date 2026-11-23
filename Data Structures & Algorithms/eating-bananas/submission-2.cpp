class Solution {
public:
    bool canEat(int mid, vector<int>& piles, int h) {
        long long step = 0;
        for (int i = 0; i < piles.size(); i++) {
            step += piles[i] / mid;
            if (piles[i] % mid != 0) {
                step++;
            }
        }
        if (step > h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int k = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (canEat(mid, piles, h)) {
                k = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return k;
    }
};
