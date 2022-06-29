class Solution {
    int countLessEqual(const vector<vector<int>>& matrix, int ths, int n, int m) {
        int count = 0;
        int i = 0, j = m - 1;
        for(; j >= 0; j--) {
            while(i < n and ths >= matrix[i][j]) {
                i++;
            }
            count += i;
        }
        return count;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int l = matrix[0][0], r = matrix[n-1][m-1];
        while(l < r) {
            int mid = l + (r - l)/2;
            if(countLessEqual(matrix, mid, n, m) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
