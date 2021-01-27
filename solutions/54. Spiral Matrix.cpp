class Solution {
    bool checkBoundaries(int x1, int x2, int y1, int y2, int x, int y) {
        bool ans = (x1 <= x2 && y1 <= y2 && x <= x2 && x >= x1 && y <= y2 && y >= y1);
        cout << "x: " << x << " y: " << y << " x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2: " << y2 << " ans: " << ans << "\n";
        return ans;
    }
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int x1, x2, y1, y2, x, y;
        x1 = y1 = x = y = 0;
        x2 = matrix.size()-1;
        if(x2 < 0)
            return ans;
        y2 = matrix[0].size()-1;
        if(y2 < 0)
            return ans;
        while(checkBoundaries(x1, x2, y1, y2, x, y)) {
            bool f1, f2, f3, f4;
            f1 = f2 = f3= f4 = false;
            for(; checkBoundaries(x1, x2, y1, y2, x, y); y++) {
                ans.push_back(matrix[x][y]);
                f1 = true;
            }
            if(f1) {
                y--;
                x1++;
                x++;
            }
            
            for(; checkBoundaries(x1, x2, y1, y2, x, y); x++) {
                ans.push_back(matrix[x][y]);                
                f2 = true;
            }
            if(f2) {
                x--;
                y2--;
                y--;
            }
            
            for(; checkBoundaries(x1, x2, y1, y2, x, y); y--) {
                ans.push_back(matrix[x][y]);                
                f3 = true;
            }
            if(f3) {
                y++;
                x2--;
                x--;
            }
            
            for(; checkBoundaries(x1, x2, y1, y2, x, y); x--) {
                ans.push_back(matrix[x][y]);                
                f4 = true;
            }
            if(f4) {
                x++;
                y1++;
                y++;
            }
        }
        return ans;
    }
};
