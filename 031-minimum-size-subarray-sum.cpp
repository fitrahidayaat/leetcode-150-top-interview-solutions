class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        
        int ans = 1e9;
        int sum = 0;

        while(r < n) {
            while(r < n && sum < target) {
                sum += nums[r];
                r++;
            }
            while(l < r && sum >= target) {
                ans = min(ans, r-l);
                sum -= nums[l];
                l++;
            }
        }
        
        
        return ans == 1e9 ? 0 : ans;
    }
};