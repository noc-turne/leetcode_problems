class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++) {
            if(!st.empty()) {
                int top = st.top();
                while(temperatures[i] > temperatures[top]) {
                    res[top] = i-top;
                    st.pop();
                    if(st.empty()) break;
                    top = st.top();
                }
            }
            
            st.push(i);
        }
        return res;

        
    }
};