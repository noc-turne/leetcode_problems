class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.size() == 0) return res;

        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] >= target) {
                r = mid;
            }
            else l = mid + 1;
        }


        if(nums[l] == target)
            res[0] = l;

        l = 0;
        r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(nums[mid] <= target) {
                l = mid;
            }
            else r = mid - 1;
        }
        if(nums[l] == target)
            res[1] = l;

        return res;


        
    }
};