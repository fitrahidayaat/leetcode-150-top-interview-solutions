class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();
        
        if(n > m) return false;
        map<char, int> mp;
        for(int i = 0; i < m; i++) {
            mp[magazine[i]]++;
        }
        
        for(int i = 0; i < n; i++) {
            mp[ransomNote[i]]--;
            if(mp[ransomNote[i]] < 0) return false;
        }
        
        return true;
    }
};