class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x;
        while(l < r) {
            long long mid = (l + r) / 2;
            if(mid * mid >= x) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        } 
        if(l * l <= x) return l;
        else return l - 1;   
    }

};