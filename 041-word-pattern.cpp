class Solution {
public:
    vector<string> split(string s) {
        string cur = "";
        vector<string> res;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                res.push_back(cur);
                cur = "";
            } else {
                cur += s[i];
            }
        }
        
        res.push_back(cur);
        
        return res;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s);
        int n = pattern.size();
        int m = words.size();
        if(n != m) return false;
        
        map<char, string> mp1;
        map<string, char> mp2;
        for(int i = 0; i < n; i++) {
            if(mp1.find(pattern[i]) == mp1.end() && mp2.find(words[i]) == mp2.end()) {
                mp1[pattern[i]] = words[i];
                mp2[words[i]] = pattern[i];
            } else if(mp1[pattern[i]] != words[i] || mp2[words[i]] != pattern[i]) {
                return false;
            };
        }
        
        return true;
    }
};