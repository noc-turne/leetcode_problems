class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> hashmap;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(hashmap.count(nums[i])) {
                hashmap[nums[i]][0] ++;
                hashmap[nums[i]][2] = i;
            }
            else {
                hashmap[nums[i]] = vector<int>{1,i,i};
            }
        }
        int res = 0;
        int maxv = -1;
        for(auto iter=hashmap.begin();iter!=hashmap.end();iter++) {
            if((iter->second)[0] > res) {
                maxv = iter->first;
                res = (iter->second)[0];
            }
            else if((iter->second)[0] == res) {
                int v1 = hashmap[maxv][2] - hashmap[maxv][1] + 1;
                int v2 = (iter->second)[2] - (iter->second)[1] + 1;
                if(v2 < v1) {
                    maxv = iter->first;
                    res = (iter->second)[0];
                }
            }
        }
        return hashmap[maxv][2] - hashmap[maxv][1] + 1;

        
        
    }
};