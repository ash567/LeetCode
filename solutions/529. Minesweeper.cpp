class Solution {
    void updateHelper(vector<vector<char>>& board, int x, int y, int n, int m) {
        if(x < 0 || x >= n || y < 0 || y >= m)
            return;
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return;
        }
        int mines = 0;
        for(int i = max(0, x-1); i <= min(n-1, x+1); i++) {
            for(int j = max(0, y-1); j <= min(y+1, m-1); j++) {
                if(board[i][j] == 'M')
                    mines++;
            }
        }
        if(mines != 0)
            board[x][y] = '0' + mines;
        else {
            board[x][y] = 'B';
            for(int i = max(0, x-1); i <= min(n-1, x+1); i++) {
                for(int j = max(0, y-1); j <= min(y+1, m-1); j++) {
                    if((i == x && j == y) || board[i][j] != 'E')
                        continue;
                    updateHelper(board, i, j, n, m);
                }
            }
        }
        return;
    }
        
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        if(n == 0)
            return board;
        int m = board[0].size();
        updateHelper(board, click[0], click[1], n, m);
        return board;
    }
};
