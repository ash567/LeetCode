class Solution {
    int countLessEqual(const vector<vector<int>>& matrix, int ths) {
        int count = 0;
        int n = matrix.size();
        int m = matrix[0].size();
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
            if(countLessEqual(matrix, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
