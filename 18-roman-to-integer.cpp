class Solution {
public:
    string intToRoman(int num) {
        string ans;
        vector<int> order = {1000, 500, 100, 50, 10, 5, 1};
        sort(order.begin(), order.end());
        map<int, char> mp;
        mp[1000] = 'M';
        mp[500] = 'D';
        mp[100] = 'C';
        mp[50] = 'L';
        mp[10] = 'X';
        mp[5] = 'V';
        mp[1] = 'I';
        
        string rev = to_string(num);
        reverse(rev.begin(), rev.end());
        int n = rev.size();
        int pw = 1;
        for(int i = 0; i < n; i++) {
            int idx = upper_bound(order.begin(), order.end(), (rev[i] - '0')*pw) - order.begin() - 1;
            int val = (rev[i] - '0')*pw;
            if(val == 4) {
                ans += "VI";
            } else if(val == 9) {
                ans += "XI";
            } else if(val == 40) {
                ans += "LX";
            } else if(val == 90) {
                ans += "CX";
            } else if(val == 400) {
                ans += "DC";
            } else if(val == 900) {
                ans += "MC";
            } else {
                int x = val;
                string temp;
                while(x > 0) {
                    idx = upper_bound(order.begin(), order.end(), x) - order.begin() - 1;
                    int cnt = x / order[idx];
                    for(int j = 0; j < cnt; j++) {
                        temp += mp[order[idx]];
                        x -= order[idx];
                    }
                }
                reverse(temp.begin(), temp.end());
                ans += temp;
                
            }
            
            pw *= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};