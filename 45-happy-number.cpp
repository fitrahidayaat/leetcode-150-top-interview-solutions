class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> mp;
        
        while(n != 1 && mp.find(n) == mp.end()) {
            int sum = 0;
            int temp = n;
            mp[n] = true;
            while(temp) {
                int d = temp % 10;
                sum += d*d;
                temp /= 10;
            }
            n = sum;
        }
        
        return n == 1;
    }
};