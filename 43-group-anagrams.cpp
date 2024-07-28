class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        int n = strs.size();
        string t;
        map<string, vector<string>> mp;
        for(int i = 0; i < n; i++) {
            t = strs[i];
            sort(t.begin(), t.end());
            mp[t].push_back(strs[i]);
        }
        
        for(auto &x:mp) {
            ans.push_back({});
            for(auto &y:x.second) {
                ans.back().push_back(y);
            }
        }
        
        return ans;
    }
};