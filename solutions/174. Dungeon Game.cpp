​
​
​
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> minCount = dungeon;
        minCount[dungeon.size()-1][dungeon[0].size()-1] = dungeon[dungeon.size()-1][dungeon[0].size()-1];
        for(int i = dungeon[0].size() - 2; i >= 0; i--) {
            minCount[dungeon.size() - 1][i] = dungeon[dungeon.size() - 1][i] + min(0, minCount[dungeon.size() - 1][i+1]);
        }
        for(int i = dungeon.size() - 2; i >= 0; i--) {
            minCount[i][dungeon[0].size() - 1] = dungeon[i][dungeon[0].size() - 1] + min(0, minCount[i+1][dungeon[0].size() - 1]);
        }
        for(int i = dungeon.size() - 2; i >= 0; i--) {
            for(int j = dungeon[0].size() - 2; j >= 0 ; j--) {
                minCount[i][j] = max(min(0, minCount[i+1][j]), min(0, minCount[i][j+1])) + dungeon[i][j];
            }
        }
        // for(int i = 0; i < dungeon.size(); i++) {
        //     for(int j = 0; j < dungeon[0].size(); j++) {
        //         cout << minCount[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return 1 + max(-minCount[0][0], 0);
    }
};
