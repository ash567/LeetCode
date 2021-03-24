class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j, n, m;
        n = matrix.size();
        if(n == 0)
            return;
        m = matrix[0].size();
        i = j = 0;
        while(i < n) {
            if(matrix[i][j] == 0) {
                break;
            }
            j = (j + 1) % m;
            if(j == 0)
                i++;
        }
        if(i == n)
            return;
        for(int k = 0; k < n; k++) {
            if(k == i)
                continue;
            if(matrix[k][j] != 0)
