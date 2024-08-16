
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dnums(n-1,0);
        for(int i=0;i<n-1;i++) {
            dnums[i] = nums[i+1] - nums[i];
        }
        int res = 0;
        int cur_diff = 1e9;
        int cur_len = -1;
        for(int i=0;i<n-1;i++) {
            if(dnums[i] != cur_diff) {
                if(cur_len >= 2) {
                    res += cur_len * (cur_len - 1) / 2;
                }
                cur_len = 1;
                cur_diff = dnums[i];
            }
            else {
                cur_len ++;
            }

        }
        if(cur_len >= 2) {
            res += cur_len * (cur_len - 1) / 2;
        }
        return res;
        
    }
};