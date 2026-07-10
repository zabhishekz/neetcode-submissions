#include<cmath>
class Solution {
public:
    bool canEat(int mid, vector<int>& piles, int h){
        int step = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] <= mid){
                step++;
            }
            else{
                int temp =  ceil((double)piles[i] / mid);
                step += temp;
            }
        }
        if(step > h){
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long s = 1;
        long e = 0;
        long k = -1;
        for(long i = 0; i < piles.size(); i++){
            e += piles[i];
        }
        while(s <= e){
            long mid = (e-s)/2 + s;
            if(canEat(mid, piles, h) == true){
                cout<<"true-"<<mid;
                k = mid;
                e = mid-1;
            }
            else{
                cout<<"false-"<<mid;
                s = mid+1;
            }
        }
        return k;
    }
};
