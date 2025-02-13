class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n+1, false));
        // 第一维是idx, 第二维是长度, 值代表长度
        for(int i=0;i<n;i++) {
            dp[i][1] = true;
            dp[i][0] = true;
        }

        for(int len=2;len<=n;len++) {
            for(int i=0;i<=n-len;i++) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    if(dp[i+1][len-2] == true) {
                        dp[i][len] = dp[i+1][len-2] + 2;
                    }
                }
            
            }
        }


        for(int len=n;len>=1;len--) {
            for(int i=0;i<=n-len;i++) {
                if(dp[i][len] == true)
                    return s.substr(i, len);
            }
        }

        return "";

        
    }
};