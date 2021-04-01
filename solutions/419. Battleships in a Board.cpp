class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return 0;
        int boardCount = 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'X') {
                    if(j > 0 && board[i][j-1] == 'X' || i > 0 && board[i-1][j] == 'X') {
                        continue;
                    }
                    boardCount++;
                }   
            }
        }
        return boardCount;
    }
};
