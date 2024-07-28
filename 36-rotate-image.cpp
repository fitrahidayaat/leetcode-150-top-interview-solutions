class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n/2; i++) {
            for(int j = i+1; j < n-i-1; j++) {
                swap(matrix[i][j], matrix[j][i]);
                swap(matrix[n-i-1][n-j-1], matrix[n-j-1][n-i-1]);
            }
            swap(matrix[i][n-i-1], matrix[n-i-1][i]);
        }
        
        
        
        for(int i = 0; i < n/2; i++) {
            for(int j = 0; j < n; j++) {
                swap(matrix[j][i], matrix[j][n-i-1]);
            }
        }
        
    }
};