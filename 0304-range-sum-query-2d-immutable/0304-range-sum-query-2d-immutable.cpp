class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        mat = matrix;
        for(int i=1;i<n;i++) {
            mat[i][0] += mat[i-1][0];
        }
        for(int i=1;i<m;i++) {
            mat[0][i] += mat[0][i-1];
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
        }

        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) return mat[row2][col2];
        if(row1 == 0) return mat[row2][col2] - mat[row2][col1-1];
        if(col1 == 0) return mat[row2][col2] - mat[row1-1][col2];
        return mat[row2][col2] - mat[row2][col1-1] - mat[row1-1][col2] + mat[row1-1][col1-1];
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */