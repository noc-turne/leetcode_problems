class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        int cur_max = -1;
        for(int i=0;i<n;i++) {
            cur_max = max(cur_max, arr[i]);
            if(cur_max == i) {
                res ++;
                cur_max = -1;
            }
        }
        return res;
        
    }
};