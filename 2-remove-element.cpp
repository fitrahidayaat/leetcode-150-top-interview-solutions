class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            idx = i;
            if(nums[i] != val) res++;
            while(idx > 0 && nums[idx-1] == val) {
                swap(nums[idx], nums[idx-1]);
                idx--;
            }
            
        }

        return res;
    }
};