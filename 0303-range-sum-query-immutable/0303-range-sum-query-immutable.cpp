class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr.push_back(nums[0]);
        for(int i=1;i<n;i++) {
            nums[i] += nums[i-1];
            arr.push_back(nums[i]);
        }
        
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return arr[right];
        return arr[right] - arr[left-1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */