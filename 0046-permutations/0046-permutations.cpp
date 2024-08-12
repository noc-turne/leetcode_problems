class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, vector<int> &pre, vector<bool> &st) {
        if(pre.size() == nums.size()) {
            res.push_back(pre);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(st[i] == false) {
                pre.push_back(nums[i]);
                st[i] = true;
                dfs(nums, pre, st);
                pre.pop_back();
                st[i] = false;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> pre;
        vector<bool> st(nums.size(), false);
        dfs(nums, pre, st);
        return res;
        
    }
};