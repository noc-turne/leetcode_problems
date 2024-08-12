class Solution {
public:
    int m, n;
    void dfs(int x, int y, vector<vector<int>> &heights, vector<vector<bool>> &st) {
        if(st[x][y]) return;
        st[x][y] = true;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        for(int i=0;i<4;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < m && xx >= 0 && yy < n && yy >= 0 && st[xx][yy] == false && heights[xx][yy] >= heights[x][y]) {
                dfs(xx, yy, heights, st);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific_st(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic_st(m, vector<bool>(n, false));

        for(int i=0;i<m;i++) {
            dfs(i, 0, heights, pacific_st);
            dfs(i, n-1, heights, atlantic_st);
        }
        for(int i=0;i<n;i++) {
            dfs(0, i, heights, pacific_st);
            dfs(m-1, i, heights, atlantic_st);
        }

        vector<vector<int>> res;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pacific_st[i][j] && atlantic_st[i][j]) {
                    res.push_back({i,j});
                }
            }
        }
        return res;
        
    }
};