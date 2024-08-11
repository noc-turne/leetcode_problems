class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        bool up = false, down = false;
        if(target == nums[l]) return true;
        if(target > nums[l]) up = true;
        else down = true;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] == nums[0]) {
                if(nums[l] == target) return true;
                l ++;
            }
            else if(nums[mid] > nums[0]) {
                if(nums[mid] == target) return true;
                else if(nums[mid] > target) {
                    if(up) r = mid - 1;
                    if(down) l = mid + 1;
                } 
                else {
                    l = mid + 1;
                }
            }
            else {
                if(nums[mid] == target) return true;
                else if(nums[mid] > target) {
                    r = mid - 1;
                }
                else {
                    if(up) r = mid - 1;
                    if(down) l = mid + 1;
                }
            }
        }

        if(nums[l] == target) return true;
        return false;
        
    }
};