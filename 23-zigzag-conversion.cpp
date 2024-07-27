class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.size();
        
        string ans = "";
        
        int k = 0;
        vector<vector<char>> temp;
        for(int i = 0; i < numRows*2 - 2; i++) {
            temp.push_back({});
            for(int j = i; j < n; j += (numRows - 2)*2+2){
                temp[i].push_back(s[j]);
            }
        }
        
        for(int i = 0; i < temp.size(); i++) {
            for(int j = 0; j < temp[i].size(); j++) {
                cout << temp[i][j] << " ";
            }
            cout << "\n";
        }
        
        for(int i = 0; i < temp[0].size(); i++) {
            ans += temp[0][i];
        }
        
        int l = 1, r = temp.size() - 1;
        while(l < r) {
            int len = max(temp[l].size(), temp[r].size());
            for(int i = 0; i < len; i++) {
                ans += temp[l][i];
                if(i < temp[r].size()) {
                    ans += temp[r][i];
                }
            }
            l++;
            r--;
        }
        if(temp.size() > 1) {
            for(int i = 0; i < temp[l].size(); i++) {
                ans += temp[l][i];
            }
        }
        
        
        return ans;
    }
};