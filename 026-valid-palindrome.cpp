class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string t = "";
        for(int i = 0; i < n; i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                t += (s[i] + 32);
            } else if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
                t += s[i];
            }
        }
        n = t.size();
        for(int i = 0; i < n/2; i++) {
            if(t[i] != t[n-i-1]) return false;
        }
        
        return true;
    }
};