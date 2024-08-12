class Solution {
public:
    // int cnt = 0;
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &st) {
        // cout << i << ' ' << j << endl;
        // cnt ++;
        // if(cnt > 50) exit(0);
        if(i < 0 || i >= grid.size()) return 0;
        if(j < 0 || j >= grid[0].size()) return 0;
        if(st[i][j]) return 0;
        st[i][j] = true;
        if(grid[i][j] == 0) {
            return 0;
        }

        int res = 1;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        for(int k=0;k<4;k++) {
            i += dx[k];
            j += dy[k];
            res += dfs(i, j, grid, st);
            i -= dx[k];
            j -= dy[k];

        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> st(m,vector<bool>(n,false));

        int area = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(st[i][j]) continue;
                area = max(area,dfs(i, j, grid, st));
                // cout << i << ' ' << j << ' ' << area << endl;
            }
        }
        return area;
        
    } 
};