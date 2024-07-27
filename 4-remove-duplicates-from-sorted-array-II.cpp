class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int idx = 0;
        for(auto &i:mp) {
            for(int j = 0; j < min(2,i.second); j++){
                nums[idx] = i.first;
                idx++;
            }
        }
        
        return idx;
    }
};