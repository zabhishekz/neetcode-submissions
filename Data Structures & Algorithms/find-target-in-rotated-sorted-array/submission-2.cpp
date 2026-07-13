class Solution {
public:
    int findMinIdx(vector<int> &nums) {
        int minIdx = 0;
        int s = 0;
        int e = nums.size()-1;

        while(s <= e){
            if(nums[s] < nums[e]){
                if(nums[s] < nums[minIdx]){
                    minIdx = s;
                }
                break;
            }
            int mid = (e-s)/2 + s;
            if(nums[mid] < nums[minIdx]){
                minIdx = mid;
            }
            
            if(nums[s] <= nums[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return minIdx;
    }
    int binary_search(vector<int>& nums, int s, int e, int target){
        while(s <= e){
            int mid = (e-s)/2 + s;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int minElIdx = findMinIdx(nums);
        if(nums[minElIdx] <= target and target <= nums[nums.size()-1]){
            return binary_search(nums, minElIdx, nums.size()-1, target);
        }
        else{
            return binary_search(nums, 0, minElIdx-1, target);
        }
    }
};
