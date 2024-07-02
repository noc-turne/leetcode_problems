class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        int n = nums.size();
        int cnt = 0;
        int psum = 0;
        hashmap[0] = 1;
        for(int i=0;i<n;i++) {
            psum += nums[i];
            if(hashmap.count(psum - k)) {
                cnt += hashmap[psum - k];
            }
            if(hashmap.count(psum)) {
                hashmap[psum] += 1;
            }
            else {
                hashmap[psum] = 1;
            }
            
        }
        return cnt;

    }
};