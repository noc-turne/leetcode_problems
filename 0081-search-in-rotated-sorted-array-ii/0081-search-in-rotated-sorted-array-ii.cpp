class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;
        int cnt = 0;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) return true;
            if(target == nums[l]) return true;
            else if(target > nums[l]) {
                if(nums[mid] > target) {
                    r = mid - 1;
                }
                else {
                    if(nums[mid] < nums[l]) {
                        r = mid;
                    }
                    else if(nums[mid] > nums[l]) {
                        l = mid;
                    }
                    else {
                        l ++;
                    }
                }
            }
            else {
                if(nums[mid] <= target) {
                    l = mid;
                }
                else {
                    if(nums[mid] > nums[l]) {
                        l = mid + 1;
                    }
                    else if(nums[mid] < nums[l]) {
                        r = mid - 1;
                    }
                    else {
                        l ++;
                    }
                }

            }
        }
        if(l < nums.size() && nums[l] == target) return true;
        return false;
        
    }
};