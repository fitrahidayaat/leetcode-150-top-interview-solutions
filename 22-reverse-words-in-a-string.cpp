class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n-1;
        string temp, ans="";
        while(i >= 0) {
            while(i >= 0 && s[i] == ' ') i--;
            temp = "";
            while(i >= 0 && s[i] != ' ') {
                temp = s[i] + temp;
                i--;
            }
            ans = ans + " " + temp;
        }
        
        int l = 0;
        int r = ans.size() - 1;
        while(l < n && ans[l] == ' ') {
            l++;
        }
        
        while(r >= 0 && ans[r] == ' ') {
            r--;
        }
        
        return ans.substr(l, r-l+1);
    }
};