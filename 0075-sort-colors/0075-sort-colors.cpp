class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        for(int i=0;i<nums.size();i++) {
            while(nums[i] == 0 && l < nums.size()) {
                if(l == i) {
                    l ++;
                    break;
                }
                swap(nums[l], nums[i]);
                l ++;
            }
        }

        int r = nums.size() - 1;

        cout << l << endl;

        for(int i=0;i<nums.size();i++) {
            cout << nums[i] << ' ';
        }
        cout << endl;
        for(int i=l;i<r;i++) {
            while(nums[i] == 2 && r >= 0) {
                if(r == i) {
                    r --;
                    break;
                }
                swap(nums[i], nums[r]);
                r --;
            }

        }
        
        
    }
};