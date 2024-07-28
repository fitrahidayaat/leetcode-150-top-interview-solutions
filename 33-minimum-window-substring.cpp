class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        int l = 0, r = 0;
        
        map<char, int> mp;
        for(int i = 0; i < n; i++) {
            mp[t[i]]++;
        }
        int ans = 1e9, ansl = 0, ansr=0, size=0;
        map<char, int> seen;
        while(r < m) {
            
            while(r < m && size < mp.size()) {
                seen[s[r]]++;
                auto itr = mp.find(s[r]);
                if(itr == mp.end()) {
                    r++;
                    continue;
                }
                
                if(seen[s[r]] == itr->second) {
                    size++;
                }
                
                r++;
            }
            
            while(size == mp.size()) {
                if(r-l <= ans) {
                    ans = r-l;
                    ansl = l;
                    ansr = r;
                }
                
                seen[s[l]]--;
                
                auto itr = mp.find(s[l]);

                if(itr != mp.end() && seen[s[l]] < itr->second) {
                    size--;
                }
                
                l++;
            }
        }
        
        return s.substr(ansl, ansr-ansl);
    }
};