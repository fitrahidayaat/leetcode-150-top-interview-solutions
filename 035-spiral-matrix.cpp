class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        string direction = "right";
        int n = matrix.size();
        int m = matrix[0].size();
        int topLim = -1, rightLim = m, bottomLim = n, leftLim = -1; 
        int cnt = 0;
        int i = 0, j = 0;
        vector<int> ans;
        while(cnt != n*m) {
            ans.push_back(matrix[i][j]);
            if(direction == "right") {
                j++;
                if(j == rightLim) {
                    j--;
                    direction = "bottom";
                    topLim++;
                    i++;
                }
            } else if(direction == "bottom") {
                i++;
                if(i == bottomLim) {
                    i--;
                    direction = "left";
                    rightLim--;
                    j--;
                }
            } else if(direction == "left") {
                j--;
                if(j == leftLim) {
                    j++;
                    direction = "top";
                    bottomLim--;
                    i--;
                }
            } else if(direction == "top") {
                i--;
                if(i == topLim) {
                    i++;
                    direction = "right";
                    leftLim++;
                    j++;
                }
            }
            cnt++;
        }
        return ans;
    }
};