class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = floor(sqrt(c));
        while(left <= right) {
            if(left * left + right * right < c) {
                left ++;
            }
            else if(left * left + right * right > c) {
                right --;
            }
            else return true;
        }
        return false;
        
    }
};