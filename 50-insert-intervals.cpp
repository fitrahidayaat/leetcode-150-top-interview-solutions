class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 1, cnt = 1;
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        while(i < n) {
            if(end >= intervals[i][0] && end < intervals[i][1]) {
                end = intervals[i][1];
            } else if(end < intervals[i][0]){
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            i++;
        }
        res.push_back({start, end});
        
        return res;
    }
};