class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(mp.find(target - nums[i]) != mp.end() && mp[target-nums[i]] != i) {
                vector<int> ans = {mp[target-nums[i]], i};
                
                return ans;
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};