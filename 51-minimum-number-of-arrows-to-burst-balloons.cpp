class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int start = points[0][0];
        int end = points[0][1];
        
        int i = 1;
        int cnt = 1;
        int n = points.size();
        while(i < n) {
            if(points[i][0] >= start && points[i][1] <= end) { //inside
                start = points[i][0];
                end = points[i][1];
            } else if (points[i][0] <= end) { //intersect
                start = points[i][0];               
            } else {
                cnt++;
                start = points[i][0];
                end = points[i][1];
            }
            i++;
        }
        
        return cnt;
    }
};