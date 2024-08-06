class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        
        int i = 1, cnt = 1;
        vector<string> res;
        if(n==0) return res;
        while(i < n) {
            if(nums[i] == nums[i-1] + 1) {
                i++;
                cnt++;
            } else {
                if(cnt == 1) {
                    res.push_back(to_string(nums[i-1]));
                } else {
                    res.push_back(to_string(nums[i-cnt]) + "->" + to_string(nums[i-1]));
                    cnt = 1;
                }
                i++;
            }
        }  
        if(cnt == 1) {
            res.push_back(to_string(nums[i-1]));
        } else {
            res.push_back(to_string(nums[i-cnt]) + "->" + to_string(nums[i-1]));
            cnt = 1;
        }
        
        return res;
    }
};