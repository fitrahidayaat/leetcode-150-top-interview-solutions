class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0;
        
        while(i < n) {
            ans[(i + k)%n] = nums[i];
            i++;
            
        }
        
        for(int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
        
    }
};