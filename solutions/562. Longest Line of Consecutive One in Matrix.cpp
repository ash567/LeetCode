class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        vector<vector< vector<int> > > maxLine(mat.size() + 2, vector<vector<int> >(mat[0].size() + 2, vector<int>(4, 0)));
        int ans = 0;
        for(int i = 1; i <= mat.size(); i++) {
            for(int j = 1; j <= mat[0].size(); j++) {
                if(mat[i-1][j-1] == 0)
                    continue;
                else {
                    maxLine[i][j][0] += maxLine[i-1][j][0] + 1;
                    maxLine[i][j][1] += maxLine[i][j-1][1] + 1;
                    maxLine[i][j][2] += maxLine[i-1][j-1][2] + 1;
                    maxLine[i][j][3] += maxLine[i-1][j+1][3] + 1;
                }
                ans = max(ans, max(max(maxLine[i][j][0], maxLine[i][j][1]), max(maxLine[i][j][2], maxLine[i][j][3])));
            }
        }
        return ans;
    }
};
