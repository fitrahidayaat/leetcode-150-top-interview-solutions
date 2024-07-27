class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int power = 0;
        for(int i = 0; i < n; i++) {
            if(power < 0) return false;
            else if(nums[i] > power) {
                power = nums[i];
            }
            power--;
        }
        
        
        return true;
    }
};