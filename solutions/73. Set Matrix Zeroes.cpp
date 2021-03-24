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
                matrix[k][j] = 0;
            else
                matrix[k][j] = 1;
        }
        for(int k = 0; k < m; k++) {
            if(matrix[i][k] != 0)
                matrix[i][k] = 0;
            else
                matrix[i][k] = 1;
        }
        for(int a = 0; a < n; a++) {
            if(a == i)
                continue;
            for(int b = 0; b < m; b++) {
                if(b == j)
                    continue;
                if(matrix[a][b] == 0) {
                    matrix[a][j] = 1;
                    matrix[i][b] = 1;
                }
            }
        }
        for(int k = 0; k < n; k++) {
            if(k == i)
                continue;
            if(matrix[k][j] == 1)
                for(int l = 0; l < m; l++) {
                    matrix[k][l] = 0;
                }
        }
        for(int k = 0; k < m; k++) {
            if(matrix[i][k] == 1)
                for(int l = 0; l < n; l++) {
                    matrix[l][k] = 0;
                }
        }
        return;
    }
};
