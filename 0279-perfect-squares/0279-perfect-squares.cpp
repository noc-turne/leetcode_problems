class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for(int i=1;i<n+1;i++){
            for(int k=1;k*k<=i;k++) {
                dp[i] = min(dp[i], dp[i-k*k] + 1);
            }
        }
        return dp[n];
    }
};