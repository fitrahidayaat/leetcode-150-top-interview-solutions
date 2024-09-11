class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int high = 0, ans = 0;
        vector<int> v(n);
        
        for(int i = 0; i < n; i++) {
            if(height[i] > high) {
                high = height[i];
            } else {
                v[i] = high - height[i];
            }
        }
        
        high = 0;
        for(int i = n-1; i >= 0; i--) {
            if(height[i] > high) {
                high = height[i];
            } else {
                ans += min(high - height[i], v[i]);
            }
        }
        
        return ans;
    }
};