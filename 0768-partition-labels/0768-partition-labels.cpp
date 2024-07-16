class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>> st;
        for(int i=0;i<26;i++) {
            char c = i + 'a';
            int left = -1, right = -1;
            for(int i=0;i<s.size();i++) {
                if(s[i] == c) {
                    left = i;
                    break;
                }
            }
            for(int i=s.size()-1;i>=0;i--) {
                if(s[i] == c) {
                    right = i;
                    break;
                }
            }
            if(left != -1 && right != -1 && left != right) {
                st.push_back({left, right});
            }
        }
        sort(st.begin(), st.end());
        if(st.empty()) {
            vector<int> res(s.size(), 1);
            return res;
        }
        int left = st[0].first, right = st[0].second;
        vector<int> res(left, 1);
        for(int i=0;i<st.size();i++) {
            if(st[i].first < right) {
                right = max(right, st[i].second);
            }
            else {
                // cout << st[i].first << ' ' << st[i].second << ' ' << left << ' ' << right << endl;
                res.push_back(right - left + 1);
                for(int j=1;j<st[i].first - right;j++)
                    res.push_back(1);
                left = st[i].first;
                right = st[i].second;
            }
        }
        res.push_back(right - left + 1);
        for(int i=1;i<s.size() - right;i++)
            res.push_back(1);
        return res;

        
    }
};