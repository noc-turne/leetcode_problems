class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i=1;i<=k;i++) {
            for(int j=0;j<=m;j++) {
                for(int u=0;u<=n;u++) {
                    dp[i][j][u] = dp[i-1][j][u];
                    int num0 = 0;
                    int num1 = 0;
                    string str = strs[i-1];
                    for(int v=0;v<str.size();v++) {
                        if(str[v] == '0') num0 ++;
                        else num1 ++;
                    }
                    // if(i==2 && j==0 && u==1) {
                    //     cout << num0 << ' ' << num1 << endl;
                    // }
                    if(j >= num0 && u >= num1) {
                        dp[i][j][u] = max(dp[i][j][u], dp[i-1][j-num0][u-num1] + 1);
                    }
                }
            }
        }

        // for(int i=0;i<=k;i++) {
        //     for(int j=0;j<=m;j++) {
        //         for(int u=0;u<=n;u++) {
        //             cout << i << ' ' << j << ' ' << u << ' ' << dp[i][j][u] << endl;
        //         }
        //     }
        // }
        return dp[k][m][n];
        
    }
};