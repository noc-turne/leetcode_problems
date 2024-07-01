class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int n = nums.size();
        dq.push_back(0);
        for(int i=1;i<k;i++) {
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        cout << dq.size() << endl;
        for(int i=0;i<n-k;i++) {
            res.push_back(nums[dq.front()]);
            if(dq.front() <= i) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i+k] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i+k);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};