class Solution {
    long MOD = 1e9 + 7;
public:
    int numWays(int steps, int arrLen) {
        int towerHieght = min(steps, arrLen);
        vector<vector<long>> tower(2, vector<long>(towerHieght, 0));
        tower[0][0] = tower[1][0] = 1;
        // for(int i = 0; i < towerHieght; i++) {
        //     tower[0][i] = tower[1][i] = 0;
        // }
        for(int i = 0; i < steps; i++) {
            int curr = i % 2;
            int pre = (i + 1) % 2;
            for(int j = 0; j < towerHieght; j++) {
                long up, down, same;
                up = down = same = 0;
                if(j < towerHieght - 1)
                    up = tower[pre][j+1];
                if(j > 0)
                    down = tower[pre][j-1];
                same = tower[pre][j];
                tower[curr][j] = (up + down + same) % MOD;
            }
        }
        return tower[(steps-1)%2][0];
        return 0;
    }
};
