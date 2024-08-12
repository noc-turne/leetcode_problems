class Solution {
public:
    void dfs(int x, vector<vector<int>> &isConnected, vector<bool> &st) {
        if(st[x]) return ;
        st[x] = true;

        vector<int> friends = isConnected[x];
        for(int i=0;i<friends.size();i++) {
            if(friends[i] == 1 && st[i] == false && i != x) {
                dfs(i, isConnected, st);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> st(n, false);
        int province = 0;
        for(int i=0;i<n;i++) {
            if(st[i]) continue;
            dfs(i, isConnected,st);
            province ++;
        }
        return province;
        
    }
};