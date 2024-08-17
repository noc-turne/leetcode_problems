class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 0) {
                    dp[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {
            pair<int,int> tmp = q.front();
            q.pop();
            for(int k=0;k<4;k++) {
                int tmp_x = tmp.first;
                int tmp_y = tmp.second;
                tmp_x += dx[k];
                tmp_y += dy[k];
                if(tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n && mat[tmp_x][tmp_y] == 1 && dp[tmp_x][tmp_y] == -1) {
                    dp[tmp_x][tmp_y] = dp[tmp.first][tmp.second] + 1;
                    q.push({tmp_x, tmp_y});
                }
            }
        }
        return dp;
                
        
    }
};