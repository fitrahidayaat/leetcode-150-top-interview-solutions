class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        map<string, int> mp;
        
        for(int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }
        
        int len = words[0].size();
        string sub;
        
        vector<int> ans;
        
        for(int i = 0; i < len; i++) {
            map<string, int> seen;
            int size = 0;
            
            for(int j = i; j < n; j += len) {
                sub = s.substr(j, len);
                
                auto itr = mp.find(sub);
                if(itr == mp.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }
                
                seen[sub]++;
                size++;
                
                while(seen[sub] > itr->second){
                    string first = s.substr(j - (size-1)*len, len);
                    size--;
                    seen[first]--;
                }
                
                if(size == words.size()) {
                    ans.push_back(j - (size-1)*len);
                }
            }
        }
        
        
        return ans;
    }
};