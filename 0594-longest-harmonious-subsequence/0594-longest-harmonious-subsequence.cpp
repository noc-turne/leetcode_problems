class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(hashmap.count(nums[i])) {
                hashmap[nums[i]] ++;
            }
            else {
                hashmap[nums[i]] = 1;
            }
        }
        int res = 0;
        while(!hashmap.empty()) {
            auto ele = (hashmap.begin())->first;
            int cnt = hashmap[ele];
            // cout << ele << ' ' << hashmap[ele] << ' ' << hashmap[ele-1] << ' ' << hashmap[ele+1] << endl;
            if(hashmap.count(ele-1)) {
                if(hashmap.count(ele + 1)) {
                    cnt += max(hashmap[ele-1], hashmap[ele+1]);
                }
                else {
                    cnt += hashmap[ele-1];
                }
            }
            else {
                if(hashmap.count(ele+1)) {
                    cnt += hashmap[ele + 1];
                }
                else {
                    cnt -= hashmap[ele];
                }
            } 
            // cout << ele << ' ' << cnt << endl;
            res = max(res,cnt);
            hashmap.erase(ele);
            
        }
        return res;
        
    }
};