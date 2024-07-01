class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            hashset.insert(nums[i]);
        }
        int res = 0;
        while(!hashset.empty()) {
            int cnt = 1;
            int k = *(hashset.begin());
            hashset.erase(k);
            int next = k+1;
            int prev = k-1;
            while(hashset.count(next)) {
                hashset.erase(next);
                next ++;
                cnt ++;
            }
            while(hashset.count(prev)) {
                hashset.erase(prev);
                prev --;
                cnt ++;
            }
            res = max(res, cnt);
        }
        return res;
        
    }
};