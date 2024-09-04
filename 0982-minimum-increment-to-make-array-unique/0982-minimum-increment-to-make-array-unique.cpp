class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int> hashmap;
        for(int i=0;i<nums.size();i++) {
            if(hashmap.count(nums[i]))
                hashmap[nums[i]] ++;
            else hashmap[nums[i]] = 1;
        }
        int ans = 0;
        for(auto it=hashmap.begin();it != hashmap.end();it++) {
            int cnt = it->second;
            int key = it->first;
            if(cnt >= 2) {
                for(int i=1;i<=cnt-1;i++) {
                    if(hashmap.count(key + i)) {
                        hashmap[key + i] ++;
                    }
                    else {
                        hashmap[key + i] = 1;
                    }

                }
            }
            ans += cnt * (cnt - 1) / 2;
        }
        return ans;


        
    }
};