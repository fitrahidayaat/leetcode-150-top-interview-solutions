class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int n = s.size();
        int high = 0;
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            if(mp[s[i]] >= high) {
                high = mp[s[i]];
                ans += high;
            } else{
                ans -= mp[s[i]];
            }
        }
        
        return ans;
    }
};