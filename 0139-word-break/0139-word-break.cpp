class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=0;i<=n;i++) {
            for(const string &k:wordDict) {
                int len = k.size();
                if(i >= len && s.substr(i-len,len) == k) {
                    dp[i] = dp[i-len];
                    if(dp[i]) break;
                }
            }
        }
        return dp[n];
        
    }
};