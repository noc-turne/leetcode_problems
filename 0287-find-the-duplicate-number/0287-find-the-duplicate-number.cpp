class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(hashset.count(nums[i])) return nums[i];
            else hashset.insert(nums[i]);
        }
        return -1;

    }
};