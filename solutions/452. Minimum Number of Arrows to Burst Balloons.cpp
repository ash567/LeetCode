class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0 || points.size() == 1)
            return points.size();
        vector< pair<int, int> > sortedPoints(points.size());
        for(int i = 0;  i < points.size(); i++) {
            sortedPoints[i] = make_pair(points[i][0], points[i][1]);
        }
        sort(sortedPoints.begin(), sortedPoints.end());
        int countArrow = 0;
        int endPoint = sortedPoints[0].second;
        for(int i = 0; i < sortedPoints.size();) {
            while(i < sortedPoints.size() && sortedPoints[i].first <= endPoint) {
                endPoint = min(endPoint, sortedPoints[i].second);
                i++;
            }
            countArrow++;
            if(i < sortedPoints.size()) {
                endPoint = sortedPoints[i].second;
            }
        }
        return countArrow;
    }
};
