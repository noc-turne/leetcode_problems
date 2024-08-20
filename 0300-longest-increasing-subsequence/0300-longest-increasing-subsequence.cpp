class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> st(n, 1e9);
        for(int i=0;i<n;i++) {
            int l = 0;
            int r = n-1;
            while(l < r) {
                int mid = (l + r + 1) / 2;
                if(st[mid] >= nums[i]) {
                    r = mid - 1; 
                }
                else {
                    l = mid;
                }
            }
            if(st[l] < nums[i]) {
                st[l+1] = min(st[l+1], nums[i]);
            }
            else {
                st[0] = min(st[0], nums[i]);
            }
            
        }
        int res = -1;
        for(int i=0;i<n;i++) {
            if(st[i] != 1e9) res = i;
        }

        // for(int i=0;i<n;i++) {
        //     cout << st[i] << endl;
        // }
        return res + 1;
        
    }
};