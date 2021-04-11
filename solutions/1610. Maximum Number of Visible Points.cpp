double PI = 180 / (2 * acos(0.0));
​
class Solution {
    double getAngle(int x, int y) {
        double angle = atan2(y, x) * PI;
        if(angle < 0)
            angle += 360;
        return angle;
    }
    
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        if(angle < 0)
            angle = -angle;
        vector<double> newPoints;
        int addExtra = 0;
        for(int i = 0; i < points.size(); i++) {
            int xp = points[i][0], yp = points[i][1];
            if(xp == location[0] && yp == location[1])
                addExtra++;
            else {
                newPoints.push_back(getAngle(xp - location[0], yp - location[1]));
            }
        }
        sort(newPoints.begin(), newPoints.end());
        int newPointSize = newPoints.size();
        double startAngle = 0, endAngle = -angle;
        int idx = 0, maxPoints = 0, backPtr = 0, N = (int) newPoints.size() ;
        
