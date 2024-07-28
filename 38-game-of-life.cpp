class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> neighbor(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {
                        if(k == 0 && l == 0) continue;
                        if(i+k < n && i + k >= 0 && j+l < m && j+l >= 0) {
                            neighbor[i][j] += board[i+k][j+l];
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j]){
                    if(neighbor[i][j] < 2 || neighbor[i][j] > 3) {
                        board[i][j] = 0;
                    }
                } else {
                    if(neighbor[i][j] == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};