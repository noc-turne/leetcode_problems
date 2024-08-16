class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int x = -1;
        int y = -1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    x = i;
                    y = j;
                    break;
                }
            }
            if(x != -1) break;
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        vector<vector<bool>> st(m, vector<bool>(n,false));
        queue<pair<int,int>> q;
        queue<pair<int,int>> border;
        q.push({x,y});
        st[x][y] = true;
        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();
            int tmp_x = -1;
            int tmp_y = -1;
            bool border_flag = false;
            for(int i=0;i<4;i++) {
                tmp_x = tmp.first;
                tmp_y = tmp.second;
                tmp_x += dx[i];
                tmp_y += dy[i];
                if(tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n && grid[tmp_x][tmp_y] == 1 && st[tmp_x][tmp_y] == false) {
                    st[tmp_x][tmp_y] = true;
                    q.push({tmp_x, tmp_y});
                }
                else if(tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n && grid[tmp_x][tmp_y] == 0){
                    border_flag = true;
                }
            }
            if(border_flag) {
                border.push(tmp);
            }
            
        }
        int step = 0;
        while(!border.empty()) {
            int len = border.size();
            for(int i=0;i<len;i++) {
                auto tmp = border.front();
                border.pop();
                for(int j=0;j<4;j++) {
                    int tmp_x = tmp.first;
                    int tmp_y = tmp.second;
                    tmp_x += dx[j];
                    tmp_y += dy[j];
                    if(tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n && grid[tmp_x][tmp_y] == 0 && st[tmp_x][tmp_y] == false) {
                        st[tmp_x][tmp_y] = true;
                        border.push({tmp_x, tmp_y});
                    }
                    else if(tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n && grid[tmp_x][tmp_y] == 1 && st[tmp_x][tmp_y] == false) {
                        return step;
                    }   
                }
            }
            step ++;
        }
        return -1;  
    }
};