class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(hashset.count(nums[i])) return true;
            hashset.insert(nums[i]);
        }
        return false;
        
    }
        
};