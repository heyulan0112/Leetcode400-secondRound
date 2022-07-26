class NumMatrix {
public:
    // Idea: using 2D prefix sum to solve it
    // classic 2D prefix sum template
    // Time complexity of func sumRegion is O(1);
    vector<vector<int>> presum;
    NumMatrix(vector<vector<int>>& matrix) {
        presum = vector<vector<int>> (matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int i=1;i<presum.size();i++){
            for(int j=1;j<presum[0].size();j++){
                presum[i][j] = matrix[i-1][j-1] + presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return presum[row2+1][col2+1] - presum[row1][col2+1] - presum[row2+1][col1] + presum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */