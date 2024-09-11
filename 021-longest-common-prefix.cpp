class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        int n = strs.size();
        for(int i = 0; i < strs[0].size(); i++) {
            bool ok = true;
            char cur = strs[0][i];
            for(int j = 0; j < n; j++) {
                if(strs[j][i] != cur) {
                    ok = false;
                }
            }
            if(!ok) {
                return ans;
            }
            ans += cur;
        }
        return ans;
    }
};