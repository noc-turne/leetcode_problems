class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 0) return true;
        int cnt = 0;
        for(int i=0;i<n-1;i++) {
            if(nums[i+1] < nums[i]) {
                if(cnt == 1) return false;
                if(i == 0 || nums[i-1] <= nums[i+1]) {
                    cnt ++;
                }
                else {
                    cnt ++;
                    nums[i+1] = nums[i];
                }
                
            }

        }
        return true;
        
    }
};