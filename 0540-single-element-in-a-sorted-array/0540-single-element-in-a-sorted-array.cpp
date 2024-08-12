class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int cnt = 0;
        while(l < r) {
            int mid = (l + r) / 2;
            if(mid % 2 == 0) {
                if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                    r = mid - 1;
                }
                else if(mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                    l = mid + 1;
                }
                else {
                    return nums[mid];
                }
            }
            else {
                if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                    l = mid + 1;
                }
                else if(mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                    r = mid - 1;
                }
            }
            // cout << l << ' ' << r << endl;
            // cnt ++;
            // if(cnt > 10) break;
        }
        return nums[l];
        
    }
};