class Solution {
public:
    bool validPalindrome(string s) {

        int n = s.size();
        int l = 0;
        int r = n - 1;
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                if(validPalindrome0(s, l, r-1) || validPalindrome0(s, l+1, r)) return true;
                else return false;

            }
        }
        return true;
        
    }

    bool validPalindrome0(string s, int l, int r) {
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
};