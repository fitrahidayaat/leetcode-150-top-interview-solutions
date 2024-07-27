class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        int pre = nums[0];
        int suf = nums[n-1];
        for(int i = 1; i < n; i++) {
            ans[i] *= pre;
            pre *= nums[i];
            ans[n-i-1] *= suf;
            suf *= nums[n-i-1];
        }
        
        return ans;
    }
};