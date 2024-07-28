class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        bool horizontal;
        for(int i = 0; i < n; i++) {
            map<int, bool> h, v;
            for(int j = 0; j < n; j++) {
                if(board[i][j] != '.') {
                    if(h.find(board[i][j]) != h.end()) {
                        return false;
                    }
                    h[board[i][j]] = true;
                }
                
                if(board[j][i] != '.') {
                    if(v.find(board[j][i]) != v.end()) {
                        return false;
                    }

                    v[board[j][i]] = true;
                }
            }
        }
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                map<int, bool> mp;
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        if(board[i*3 + k][j*3 + l] != '.') {
                            if(mp.find(board[i*3 + k][j*3 + l]) != mp.end()) {
                                return false;
                            }
                            mp[board[i*3 + k][j*3 + l]] = true;
                        }
                    }
                }
            }
        }
        
        return true;
        
        
    }
};