class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        q.push(0);
        vector<int> vertices(n,0);
        vector<bool> st(n, false);
        st[0] = true;
        vertices[0] = 1;
        while(1) {
            while(q.size()) {
                int n = q.size();
                for(int i=0;i<n;i++) {
                    int node = q.front();
                    q.pop();
                    for(int j=0;j<graph[node].size();j++) {
                        int new_node = graph[node][j];
                        if(vertices[new_node] == vertices[node]) return false;
                        else {
                            vertices[new_node] = -vertices[node];
                            if(st[new_node] == false) {
                                st[new_node] = true;
                                q.push(new_node);
                            }
                        }
                    }
                        
                }
            
            }
            bool flag = true;
            for(int i=0;i<n;i++) {
                if(st[i] == false) {
                    q.push(i);
                    st[i] = true;
                    vertices[i] = 1;
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }
        return true;

        
    }
};