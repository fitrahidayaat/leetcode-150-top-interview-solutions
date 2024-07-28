class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0 && !visited[i][j]) {
                    for(int p = 0; p < n; p++) {
                        if(matrix[p][j])visited[p][j] = true;
                        matrix[p][j] = 0;
                    }
                    for(int p = 0; p < m; p++) {
                        if(matrix[i][p]) visited[i][p] = true;
                        matrix[i][p] = 0;
                    }
                }
            }
        }
    }
};