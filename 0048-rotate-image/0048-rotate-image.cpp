class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n/2;i++) {
            int length = n-2*i;
            for(int j=0;j<length-1;j++) {
                // cout << i+j << ' ' << i << endl;
                // cout << i+length-1 << ' ' << i+j << endl;
                // cout << i+length-1-j << ' ' << i+length-1 << endl;
                // cout << i << ' ' << i+length-1-j << endl;
                // cout << endl;
                int tmp = matrix[i+j][i];
                matrix[i+j][i] = matrix[i+length-1][i+j];
                matrix[i+length-1][i+j] = matrix[i+length-1-j][i+length-1];
                matrix[i+length-1-j][i+length-1] = matrix[i][i+length-1-j];
                matrix[i][i+length-1-j] = tmp;

            }
        }

    }
};